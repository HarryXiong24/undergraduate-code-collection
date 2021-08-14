import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";

export interface ITabPanelProps extends IProps {
    id?: string,
    tabId?: string,
    selected?: boolean
}

export class TabPanel extends React.Component<ITabPanelProps> {
    public static readonly displayName = 'Ts:TabPanel'

    public render() {
        const classes = cn(`${PREFIX}-tab-panel`, {
            [`${PREFIX}-tab-panel-selected`]: this.props.selected
        }, this.props.className)
        return (
            <div
                role="tab-panel"
                className={classes}
                id={this.props.id}
                aria-labelledby={this.props.tabId}
            >
                {this.props.children}
            </div>
        )
    }
}
