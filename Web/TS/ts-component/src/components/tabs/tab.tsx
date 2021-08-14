import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {safeInvoke} from "../../common/utils";

export interface ITabProps extends IProps {
    id?: string,
    panelId?: string,
    disabled?: boolean,
    selected?: boolean,
    index?: number,
    ref?: (ref: HTMLLIElement) => void,
    onTabClick?: (index: number, tab: Tab) => void
}

export class Tab extends React.Component<ITabProps> {
    public static readonly displayName = 'Ts:Tab'

    private tabElement: HTMLLIElement

    private handleTabRef = (ref: HTMLLIElement) => {
        this.tabElement = ref
        safeInvoke(this.props.ref, ref)
    }

    public render() {
        const classes = cn(`${PREFIX}-tab`, {
            [`${PREFIX}-tab-disabled`]: this.props.disabled,
            [`${PREFIX}-tab-selected`]: this.props.selected
        }, this.props.className)
        return (
            <li
                role="tab"
                className={classes}
                onMouseDown={this.handleTabClick}
                ref={this.handleTabRef}
                id={this.props.id}
                data-index={this.props.index}
                tabIndex={this.props.disabled ? null : 0}
                aria-controls={this.props.panelId}
                aria-selected={this.props.selected}
                aria-disabled={this.props.disabled}
                aria-expanded={this.props.selected}
            >
                {this.props.children}
            </li>
        )
    }

    public handleTabClick = () => {
        if(!this.props.disabled) {
            safeInvoke(this.props.onTabClick, this.props.index, this)
        }
    }
}
