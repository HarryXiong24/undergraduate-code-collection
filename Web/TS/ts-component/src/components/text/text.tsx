import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";

import './text.scss'

export interface ITextProps extends IProps {
    ellipsis?: boolean,
    tagName?: keyof JSX.IntrinsicElements
}

export interface ITextState {
    textContent: string,
    isContentOverflow: boolean
}

export class Text extends React.PureComponent<ITextProps, ITextState> {
    public static displayName = 'Ts:Text'

    public static defaultProps = {
        ellipsis: false,
        tagName: 'div'
    }

    public state: ITextState = {
        textContent: '',
        isContentOverflow: false
    }

    private textElement: HTMLElement

    private refHandlers = {
        text: (ref: HTMLElement) => {
            this.textElement = ref
        }
    }

    public componentDidUpdate() {
        this.updateState()
    }

    public componentDidMount() {
        this.updateState()
    }

    private updateState() {
        if (this.textElement) {
            this.setState({
                textContent: this.textElement.textContent,
                isContentOverflow: this.props.ellipsis && this.textElement.scrollWidth > this.textElement.clientWidth
            })
        }

    }

    public render() {
        const {tagName, children} = this.props
        const {textContent, isContentOverflow} = this.state
        const textClasses = cn({
            [`${PREFIX}-text-ellipsis`]: this.props.ellipsis
        }, this.props.className)
        return React.createElement(tagName, {
            className: textClasses,
            title: isContentOverflow ? textContent : undefined,
            ref: this.refHandlers.text
        }, children)
    }
}
