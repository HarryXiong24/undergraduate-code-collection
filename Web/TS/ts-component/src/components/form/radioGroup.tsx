import * as React from 'react'
import * as cn from 'classnames'
import {PREFIX} from "../../common/constants";
import {IProps} from "../../common/props";
import {IRadioProps, Radio} from "./control";

export interface IRadioGroupProps extends IProps {
    disabled?: boolean,
    inline?: boolean,
    label?: string,
    name?: string,
    onChange?: (checked: boolean, val: any) => void,
    selectedValue?: any
}

export class RadioGroup extends React.Component<IRadioGroupProps> {
    public static displayName = 'Ts:RadioGroup'

    public static defaultProps = {
        inline: true
    }

    public render() {
        const classes = cn(`${PREFIX}-radio-group`, {
            [`${PREFIX}-radio-group-inline`]: this.props.inline
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
            return <div className={`${PREFIX}-radio-group-label`}>{this.props.label}</div>
        }
        return null
    }

    private renderChildren() {
        return React.Children.map(this.props.children, (child: React.ReactElement<IRadioProps>) => {
            if(child.type == Radio) {
                return React.cloneElement(child, {
                    disabled: child.props.disabled || this.props.disabled,
                    checked: child.props.value == this.props.selectedValue,
                    name: child.props.name || this.props.name,
                    onChange: this.props.onChange
                })
            } else {
                return child
            }
        })
    }
}
