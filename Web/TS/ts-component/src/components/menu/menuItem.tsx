import * as React from 'react'
import * as cn from 'classnames'
import {IActionProps, ILinkProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {IPopoverPops, Popover, PopperInteractionKind} from "../popover/popover";
import {Text} from "../text/text";
import {isUndefined} from "../../common/utils";
import {PositionKind} from "../../common/kinds";
import {Menu} from "./menu";
import {Icon} from "../..";

export interface IMenuItemProps extends IActionProps, ILinkProps {
    text: React.ReactNode,
    active?: boolean,
    disabled?: boolean,
    children?: React.ReactNode,
    ellipsis?: boolean,
    popoverProps?: Partial<IPopoverPops>,
    popoverDismiss?: boolean,
    tagName?: keyof JSX.IntrinsicElements
}

export class MenuItem extends React.PureComponent<IMenuItemProps> {
    public static displayName = 'Ts:MenuItem'

    public static defaultProps = {
        tagName: 'a',
        ellipsis: true,
        popoverDismiss: true,
        disabled: false
    }

    public render() {
        const {
            tagName: TagName,
            text,
            active,
            disabled,
            className,
            popoverDismiss,
            children,
            iconName,
            ellipsis,
            ...htmlProps
        } = this.props
        const hasSubmenu = !isUndefined(children)
        const targetClasses = cn(`${PREFIX}-menu-item`, {
            [`${PREFIX}-menu-item-active`]: active,
            [`${PREFIX}-menu-item-disabled`]: disabled,
            [`${PREFIX}-popover-dismiss`]: popoverDismiss && !disabled && !hasSubmenu,
        }, className)
        const target = (
            // @ts-ignore
            <TagName className={targetClasses} {...htmlProps}>
                {iconName && <Icon name={iconName}/>}
                <Text className={`${PREFIX}-menu-item-fill`} ellipsis={ellipsis}>{text}</Text>
                {hasSubmenu && <Icon name="arrow-right"/>}
            </TagName>
        )
        return (
            <li className={`${PREFIX}-submenu`}>
                {this.renderPopover(target)}
            </li>
        )
    }

    private renderPopover(target: React.ReactElement) {
        const {disabled, children} = this.props
        const hasSubmenu = !isUndefined(children)
        return (
            <Popover
                usePortal={false}
                autoFocus={false}
                minimal={true}
                disabled={disabled}
                target={target}
                content={hasSubmenu ? <Menu>{children}</Menu> : null}
                interactionKind={PopperInteractionKind.HOVER}
                position={PositionKind.RIGHT_TOP}/>
        )
    }
}
