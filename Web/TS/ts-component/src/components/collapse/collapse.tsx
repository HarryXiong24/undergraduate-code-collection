import * as cn from 'classnames'
import * as React from 'react'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";

export interface ICollapseProps extends IProps {
    component?: React.ReactType,
    isOpen?: boolean,
    duration?: number
}

export interface ICollapseState {
    height?: string
}

export class Collapse extends React.Component<ICollapseProps, ICollapseState> {
    public static readonly displayName = 'Ts:Collapse'

    public static defaultProps = {
        component: 'div',
        isOpen: false,
        duration: 200
    }

    private contents: HTMLElement

    private height: number = 0

    public state = {
        height: '0px'
    }

    componentWillReceiveProps(nextProps: ICollapseProps) {
        this.height = this.contents.clientHeight
        if (nextProps.isOpen != this.props.isOpen) {
            this.setState({
                height: nextProps.isOpen ? `${this.height}px` : '0px'
            })
        }
    }

    public contentsRefHandler = (element: HTMLElement) => {
        this.contents = element
        this.height = this.contents.clientHeight
        this.setState({
            height: `${this.height}px`
        })
    }

    // bug 有延迟
    public updateHeight = () => {
        if(this.height != this.contents.clientHeight) {
            this.height = this.contents.clientHeight
            this.setState({
                height: `${this.height}px`
            })
        }
    }

    public render() {
        const containerStyle = {
            overflow: 'hidden',
            height: this.props.isOpen ? this.state.height : '0px',
            transition: `height ${this.props.duration / 1000}s`
        }
        return React.createElement(this.props.component, {
            className: cn(`${PREFIX}-collapse`, this.props.className),
            style: containerStyle,
            onTransitionEnd: this.updateHeight
        }, <div className={`${PREFIX}-collapse-body`} ref={this.contentsRefHandler}>
            {this.props.children}
        </div>)
    }
}
