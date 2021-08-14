import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../../src/common/props";

import './stack.scss'

export interface IStackProps extends IProps {
    vertical?: boolean,
}

export class Stack extends React.Component<IStackProps> {
    public static readonly displayName = 'Stack'

    public static defaultProps = {
        vertical: false
    }

    public render() {
        const classes = cn('stack', {
            'stack-vertical': this.props.vertical
        }, this.props.className)
        return (
            <div className={classes}>
                {this.renderChild()}
            </div>
        )
    }

    private renderChild() {
        return React.Children.map(this.props.children, (child: React.ReactElement<any>) => {
            if(child.type == StackItem) {
                return child
            } else {
                return <StackItem>{child}</StackItem>
            }
        })
    }
}

export class StackItem extends React.Component<IProps> {
    public render() {
        const classes = cn('stack-item', this.props.className)
        return (
            <div className={classes}>{this.props.children}</div>
        )
    }
}
