import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../../src/common/props";

import './card.scss'

export interface ICardProps extends IProps {
    title?: string
}

export class Card extends React.Component<ICardProps> {
    public static readonly displayName = 'Card'

    public render() {
        const classes = cn('card', this.props.className)
        return (
            <div className={classes}>
                {this.maybeRenderCardHeader()}
                {this.renderCardSection()}
            </div>
        )
    }

    private maybeRenderCardHeader() {
        if(this.props.title != null) {
            return <CardHeader>{this.props.title}</CardHeader>
        }
        return null
    }

    private renderCardSection() {
        return React.Children.map(this.props.children, (child: React.ReactElement<any>) => {
            if(child.type == CardSection) {
                return child
            } else {
                return <CardSection>{child}</CardSection>
            }
        })
    }
}

export class CardHeader extends React.Component<IProps> {
    public render() {
        const classes = cn('card-header', this.props.className)
        return (
            <div className={classes}>{this.props.children}</div>
        )
    }
}

export class CarSectionHeader extends React.Component<IProps> {
    public render() {
        const classes = cn('card-section-header', this.props.className)
        return (
            <div className={classes}>{this.props.children}</div>
        )
    }
}

export class CardSection extends React.Component<ICardProps> {
    public render() {
        const classes = cn('card-section', this.props.className)
        return (
            <div className={classes}>
                {this.maybeRenderCardSectionHeader()}
                {this.props.children}
            </div>
        )
    }

    public maybeRenderCardSectionHeader() {
        if(this.props.title != null) {
            return <CarSectionHeader>{this.props.title}</CarSectionHeader>
        }
        return null
    }
}


