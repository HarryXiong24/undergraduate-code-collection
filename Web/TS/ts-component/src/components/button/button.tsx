import * as cn from 'classnames'
import * as React from 'react'
import {IActionProps, IAppearanceProps} from "../../common/props";
import {Icon} from "../icon/icon";
import {PREFIX} from "../../common/constants";

import './button.scss'

export interface IButtonProps extends IActionProps, IAppearanceProps {
    rightIconName?: string,
    leftIconName?: string,
}

/**
 * icon 待完善
 */
export class Button extends React.Component<IButtonProps, {}> {
    public static readonly displayName = 'Ts:Button'

    public render() {
        const {text, children, rightIconName, leftIconName, disabled, type, size, className, ...rest} = this.props
        const buttonClasses = cn(
            `${PREFIX}-btn`,
            {
                [`${PREFIX}-btn-disabled`]: disabled,
                [`${PREFIX}-btn-${type}`]: type,
                [`${PREFIX}-btn-${size}`]: size
            },
            className
        )
        return (
            <button
                {...rest}
                className={buttonClasses}
                type="button"
            >
                {leftIconName && <Icon name={leftIconName}/>}
                {text}
                {children}
                {rightIconName && <Icon name={rightIconName}/>}
            </button>
        )
    }
}
