import * as React from 'react'
import * as cn from 'classnames'
import {PREFIX} from "../../common/constants";
import {IProps} from "../../common/props";
import {Checkbox, ICheckboxProps} from "./control";
import {safeInvoke} from "../../common/utils";

export interface ICheckboxGroupProps extends IProps {
    disabled?: boolean,
    inline?: boolean,
    label?: string,
    name?: string,
    onChange?: (checked: boolean, val: any) => void,
    selectedValue: any[]
}

export class CheckboxGroup extends React.Component<ICheckboxGroupProps> {
    public static displayName = 'Ts:CheckboxGroup'

    public static defaultProps = {
        inline: true
    }

    public render() {
        const classes = cn(`${PREFIX}-checkbox-group`, {
            [`${PREFIX}-checkbox-group-inline`]: this.props.inline
        }, this.props.className)
        return (
            <div className={classes}>
                {this.maybeRenderLabel()}
                <div>
                    {this.renderChildren()}
                </div>
            </div>
        )
    }

    private maybeRenderLabel() {
        if(this.props.label != null) {
            return <div className={`${PREFIX}-checkbox-group-label`}>{this.props.label}</div>
        }
        return null
    }

    private renderChildren() {
        return React.Children.map(this.props.children, (child: React.ReactElement<ICheckboxProps>) => {
            if(child.type == Checkbox) {
                return React.cloneElement(child, {
                    disabled: child.props.disabled || this.props.disabled,
                    checked: this.props.selectedValue.some(value => value == child.props.value),
                    name: child.props.name || this.props.name,
                    onChange: this.handleChange
                })
            } else {
                return child
            }
        })
    }

    private handleChange = (checked: boolean, value: any) => {
        if(checked) {
            // @ts-ignore
            safeInvoke(this.props.onChange, checked, Array.from(new Set([...this.props.selectedValue, value])))
        } else {
            safeInvoke(this.props.onChange, checked, this.props.selectedValue.filter(val => val != value))
        }
    }

}
