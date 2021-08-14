import * as React from 'react'
import {findDOMNode} from 'react-dom'
import * as cn from 'classnames'
import {CSSTransition, TransitionGroup} from 'react-transition-group'
import {IProps} from "../../common/props";
import {safeInvoke} from "../../common/utils";
import {Portal} from "../portal/portal";
import {PREFIX} from "../../common/constants";
import {ESCAPE} from "../../common/keys";

import './overlay.scss'

export interface IOverlayLifeCircleProps {
    onClosing?: (element: HTMLElement) => void,
    onClosed?: (element: HTMLElement) => void,
    onOpening?: (element: HTMLElement) => void,
    onOpened?: (element: HTMLElement) => void
}

export interface IBackdropProps {
    backdropClassName?: string,
    backdropProps?: React.HTMLProps<HTMLDivElement>,
    canOutsideClickClose?: boolean,
    hasBackdrop?: boolean
}

export interface IOverlayProps extends IOverlayLifeCircleProps, IBackdropProps, IProps {
    isOpen?: boolean,
    transitionName?: string,
    autoFocus?: boolean,
    canEscapeKeyClose?: boolean,
    transitionDuration?: number,
    portalClassName?: string,
    portalContainer?: HTMLElement,
    onClose?: (event: React.SyntheticEvent<HTMLElement>) => void,
    usePortal?: boolean,
}

export class Overlay extends React.Component<IOverlayProps> {
    public static readonly displayName = 'Ts:Overlay'

    public static defaultProps = {
        autoFocus: true,
        backdropProps: {},
        canEscapeKeyClose: true,
        canOutsideClickClose: true,
        hasBackdrop: true,
        isOpen: false,
        transitionDuration: 300,
        transitionName: `${PREFIX}-overlay-transition`,
        usePortal: true
    }

    private static openStack: Overlay[] = []

    private static getLastOpened() {
        return this.openStack[Overlay.openStack.length - 1]
    }

    public containerElement: HTMLElement

    public portalContainerElement: HTMLElement

    private containerRef = (ref: React.ReactInstance) => {
        this.containerElement = findDOMNode(ref) as HTMLElement
    }

    private portalContainerRef = (ref: HTMLElement) => {
        this.portalContainerElement = ref
    }

    public componentDidUpdate(prevProps: IOverlayProps) {
        if (prevProps.isOpen && !this.props.isOpen) {
            this.overlayWillClose();
        } else if (!prevProps.isOpen && this.props.isOpen) {
            this.overlayWillOpen();
        }
    }

    public componentDidMount() {
        if (this.props.isOpen) {
            this.overlayWillOpen()
        }
    }

    public componentWillUnmount() {
        this.overlayWillClose()
    }

    public render() {
        const transitionContents = this.props.isOpen ? React.Children.map(this.props.children, this.maybeRenderChild) : []
        transitionContents.unshift(this.maybeRenderBackdrop())
        const transitionGroupClass = cn(`${PREFIX}-overlay`, this.props.className, {
            [`${PREFIX}-overlay-opened`]: this.props.isOpen
        })
        const transitionGroup = (
            <TransitionGroup
                appear={true}
                component={'div'}
                className={transitionGroupClass}
                onKeyDown={this.handleKeyDown}
                ref={this.containerRef}
            >
                {transitionContents}
            </TransitionGroup>
        )

        return (
            this.props.usePortal ?
                <Portal className={this.props.portalClassName} containerRef={this.portalContainerRef}
                        container={this.props.portalContainer}>
                    {transitionGroup}
                </Portal> :
                transitionGroup
        )
    }

    private maybeRenderChild = (child?: React.ReactChild) => {
        if (child == null) {
            return child
        }
        const content = typeof child == 'object' ?
            React.cloneElement(child, {
                className: cn(`${PREFIX}-overlay-content`, child.props.className),
                tabIndex: 0
            }) :
            <span className={cn(`${PREFIX}-overlay-content`, this.props.className)}>{child}</span>
        const {onClosing, onClosed, onOpening, onOpened, transitionDuration, transitionName} = this.props
        return (
            <CSSTransition
                key={`${PREFIX}-overlay-content-key`}
                classNames={transitionName}
                onEntering={onOpening}
                onEntered={onOpened}
                onExiting={onClosing}
                onExited={onClosed}
                timeout={transitionDuration}
            >
                {content}
            </CSSTransition>
        )
    }

    private maybeRenderBackdrop() {
        const {
            backdropClassName,
            backdropProps,
            hasBackdrop,
            isOpen,
            transitionDuration,
            transitionName,
            canOutsideClickClose
        } = this.props;

        if (hasBackdrop && isOpen) {
            const extendBackdropProps = {...backdropProps, tabIndex: canOutsideClickClose ? 0 : -1}
            return (
                <CSSTransition
                    key={`${PREFIX}-overlay-backdrop-key`}
                    classNames={transitionName}
                    timeout={transitionDuration}
                >
                    <div
                        {...extendBackdropProps}
                        className={cn(`${PREFIX}-overlay-backdrop`, backdropClassName)}
                        onMouseDown={this.handleBackdropMouseDown}
                    >
                    </div>
                </CSSTransition>
            )
        }
        return null
    }

    private handleKeyDown = (event: React.KeyboardEvent<HTMLElement>) => {
        const {canEscapeKeyClose, onClose} = this.props
        if (event.which == ESCAPE && canEscapeKeyClose) {
            safeInvoke(onClose, event)
            event.preventDefault()
        }
    }

    private handleBackdropMouseDown = (event: React.MouseEvent<HTMLDivElement>) => {
        const {backdropProps, canOutsideClickClose, onClose} = this.props
        if (canOutsideClickClose) {
            safeInvoke(onClose, event)
        }
        safeInvoke(backdropProps.onClick, event)
    }

    private focusInsideOverlay() {
        return requestAnimationFrame(() => {
            if (!this.props.isOpen || !document.activeElement) {
                return
            }
            if (this.containerElement.contains(document.activeElement)) {
                return
            }
            const focusElement = this.containerElement.querySelector('[tabindex]') as HTMLElement
            if (focusElement) {
                focusElement.focus()
            }
        })
    }

    private overlayWillOpen() {
        Overlay.openStack.push(this)
        if (this.props.autoFocus) {
            this.focusInsideOverlay()
        }
        if (this.props.isOpen && this.props.hasBackdrop) {
            document.body.classList.add(`${PREFIX}-document-overlay`)
        }

        if (this.props.canOutsideClickClose && !this.props.hasBackdrop) {
            document.addEventListener('mousedown', this.handleDomMouseDown)
        }
    }

    private handleDomMouseDown = (event: MouseEvent) => {
        const {isOpen, canOutsideClickClose, onClose,} = this.props
        const target = event.target as HTMLElement
        const currentIndex = Overlay.openStack.indexOf(this)
        const hasOverlayHandleDomClick = Overlay.openStack
            .slice(currentIndex)
            .some((overlay: Overlay) => overlay.containerElement && overlay.containerElement.contains(target))

        if (isOpen && canOutsideClickClose && !hasOverlayHandleDomClick) {
            safeInvoke(onClose, event)
        }
    }

    private overlayWillClose() {
        const currentIndex = Overlay.openStack.indexOf(this)
        if (currentIndex != -1) {
            Overlay.openStack.splice(currentIndex, 1)
            if (Overlay.openStack.length) {
                const lastOverlay = Overlay.getLastOpened()
                lastOverlay.focusInsideOverlay()
                if(Overlay.openStack.every(o => !o.props.hasBackdrop)) {
                    document.body.classList.remove(`${PREFIX}-document-overlay`)
                }
            } else {
                document.body.classList.remove(`${PREFIX}-document-overlay`)
            }
        }
        document.removeEventListener("mousedown", this.handleDomMouseDown)
    }

}


