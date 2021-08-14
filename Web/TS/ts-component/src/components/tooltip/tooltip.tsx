import * as React from 'react'
import * as cn from 'classnames'
import {IAppearanceProps} from "../../common/props";
import {IPopoverPops, Popover, PopperInteractionKind} from "../popover/popover";
import {PREFIX} from "../../common/constants";

import './tooltip.scss'

export interface ITooltipProps extends IPopoverPops, IAppearanceProps {
    content?: JSX.Element | string,
    hoverCloseDelay?: number,
    hoverOpenDelay?: number
}

export class Tooltip extends React.Component<ITooltipProps> {
    public static displayName = 'Ts:Tooltip'

    public render() {
        const {children, className, type, ...rest} = this.props
        const tooltipClasses = cn(`${PREFIX}-tooltip-wrapper`, className)
        const popoverClasses = cn(`${PREFIX}-tooltip`, {
            [`${PREFIX}-tooltip-${type}`]: type
        })
        return (
            <Popover {...rest} className={tooltipClasses} popoverClassName={popoverClasses} interactionKind={PopperInteractionKind.HOVER_TARGET}>
                {children}
            </Popover>
        )
    }
}
