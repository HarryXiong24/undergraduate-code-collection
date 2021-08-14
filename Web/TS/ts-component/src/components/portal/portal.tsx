import * as React from 'react'
import * as cn from 'classnames'
import {createPortal} from 'react-dom'
import {IProps} from "../../common/props";
import {safeInvoke} from "../../common/utils";
import {PREFIX} from "../../common/constants";

import './portal.scss'

export interface IPortalProps extends IProps, React.HTMLProps<HTMLDivElement> {
    containerRef?: (ref: HTMLElement) => void,
    onChildrenMount?: () => void,
    container?: HTMLElement
}

export class Portal extends React.Component<IPortalProps> {
    public static readonly displayName = 'Ts:Portal'
    private readonly targetElement: HTMLElement

    public static defaultProps = {
        container: document.body
    }

    constructor(props) {
        super(props);

        const targetElement = document.createElement('div')
        this.targetElement = targetElement
        this.props.container.appendChild(targetElement)
    }

    public componentDidMount() {
        safeInvoke(this.props.onChildrenMount)
    }

    public componentWillUnmount() {
        this.targetElement.remove()
    }

    public render() {
        const {className, children, containerRef, ...rest} = this.props
        const classes = cn(`${PREFIX}-portal`, className)
        return createPortal(<div
            {...rest}
            className={classes}
            ref={containerRef}>
            {children}
        </div>, this.targetElement)
    }
}
