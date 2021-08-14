import * as React from 'react'
import * as cn from 'classnames'
import {PREFIX} from "../../common/constants";
import {IProps} from "../../common/props";
import {removeProps, safeInvoke} from "../../common/utils";

import './control.scss'
import {ChangeEvent, HTMLProps} from "react";

export interface IControlProps extends IProps, HTMLProps<HTMLInputElement> {
    checked?: boolean,
    disabled?: boolean,
    name?: string,
    value?: any,
    label?: string,
    inputRef?: (ref: HTMLInputElement) => void,
    onChange?: (checked: any, value?: any) => void
}

export class Control<P extends IControlProps> extends React.Component<P> {
    protected handleChange = (event: ChangeEvent) => {
        safeInvoke(this.props.onChange, (event.target as HTMLInputElement).checked, (event.target as HTMLInputElement).value)
    }

    protected renderControl(type: 'checkbox' | 'radio', className?: string, inputRef = this.props.inputRef) {
        const classes = cn(`${PREFIX}-control`, className, {
            [`${PREFIX}-control-disabled`]: this.props.disabled
        }, this.props.className)
        return (
            <label className={classes}>
                <input
                    {...removeProps(this.props, ['children', 'indeterminate'])}
                    type={type}
                    ref={inputRef}
                    name={this.props.name}
                    onChange={this.handleChange}
                />
                <span className={`${PREFIX}-control-indicator`}/>
                {this.props.label}
                {this.props.children}
            </label>
        )
    }
}

export interface ICheckboxProps extends IControlProps {
    indeterminate?: boolean
}

export class Checkbox extends Control<ICheckboxProps> {
    public static displayName = 'Ts:Checkbox'

    private inputElement: HTMLInputElement

    public render() {
        return this.renderControl('checkbox', `${PREFIX}-checkbox`, this.handleRef)
    }

    public componentDidMount() {
        this.updateIndeterminate()
    }

    public componentDidUpdate() {
        this.updateIndeterminate()
    }

    private updateIndeterminate() {
        if(this.props.indeterminate != null) {
            this.inputElement.indeterminate = this.props.indeterminate
        }
    }

    private handleRef = (ref: HTMLInputElement)=> {
        this.inputElement = ref
        safeInvoke(this.props.inputRef, ref)
    }
}

export interface ISwitchProps extends IControlProps {}

export class Switch extends Control<ISwitchProps> {
    public static displayName = 'Ts:Switch'

    public render() {
        return this.renderControl('checkbox', `${PREFIX}-switch`)
    }
}

export interface IRadioProps extends IControlProps {}

export class Radio extends Control<IRadioProps> {
    public static displayName = 'Ts:Radio'

    public render() {
        return this.renderControl('radio', `${PREFIX}-radio`)
    }
}
