import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";

export interface ITabListProps extends IProps {
    indicatorStyle?: React.CSSProperties,
    animated?: boolean
}

export class TabList extends React.Component<ITabListProps> {
    public static readonly displayName = 'Ts:TabList'

    public static defaultProps = {
        animated: true
    }

    public render() {
        const classes = cn(`${PREFIX}-tab-list`, this.props)
        const indicatorClasses = cn(`${PREFIX}-tab-indicator`, {
            [`${PREFIX}-tab-indicator-animation`]: this.props.animated
        })
        return (
            <ul className={classes}>
                <div className={indicatorClasses} style={this.props.indicatorStyle}>
                    <div className={`${PREFIX}-tab-indicator-block`} />
                </div>
                {this.props.children}
            </ul>
        )
    }
}
