import * as React from 'react'
import * as cn from 'classnames'
import {Data, ModifierFn, Modifiers as PopperModifiers, Placement} from 'popper.js'
import {IOverlayProps, Overlay} from "../overlay/overlay";
import {IProps} from "../../common/props";
import {isUndefined, safeInvoke} from "../../common/utils";
import {AbstractComponent} from "../../common/abstractComponent";
import {Manager, Popper, PopperChildrenProps, Reference, ReferenceChildrenProps} from "react-popper";
import {PREFIX} from "../../common/constants";
import {getTransformOrigin, positionToPlacement} from "./popoverUtil";
import {PositionKind} from "../../common/kinds";

import './popover.scss'

export {
    PopperModifiers
}

export enum PopperInteractionKind {
    CLICK = 'click',
    HOVER = 'hover',
    HOVER_TARGET = 'hover-target'
}

export interface IPopoverPops extends IOverlayProps, IProps {
    content?: React.ReactNode,
    position?: PositionKind | 'auto',
    wrapperTagName?: string | keyof JSX.IntrinsicElements,
    disabled?: boolean,
    isOpen?: boolean,
    defaultIsOpen?: boolean,
    modifiers?: PopperModifiers,
    onInteraction?: (nextOpenState: boolean, event: React.SyntheticEvent<HTMLElement>) => void,
    interactionKind?: PopperInteractionKind,
    minimal?: boolean,

    hoverCloseDelay?: number,
    hoverOpenDelay?: number,

    popoverClassName?: string,
    popoverRef?: (ref: HTMLDivElement) => void,
    popoverWillClose?: () => void,
    popoverWillOpen?: () => void,
    popoverDidOpen?: () => void,

    target?: React.ReactNode,
    targetClassName?: string,
    targetTagName?: string | keyof JSX.IntrinsicElements,
    openOnTargetFocus?: boolean,
}

export interface IPopoverState {
    isOpen: boolean,
    transformOrigin: string
}

export class Popover extends AbstractComponent<IPopoverPops, IPopoverState> {
    public static displayName = 'Ts:Popover'

    public static defaultProps = {
        defaultIsOpen: false,
        disabled: false,
        hoverCloseDelay: 100,
        hoverOpenDelay: 100,
        transitionDuration: 100,
        modifiers: {},
        openOnTargetFocus: true,
        position: 'auto',
        wrapperTagName: 'span',
        targetTagName: 'span',
        hasBackdrop: false,
        minimal: false,
        interactionKind: PopperInteractionKind.CLICK
    }

    public popoverElement: HTMLElement

    public targetElement: HTMLElement

    private refHandlers = {
        popover: (ref: HTMLElement) => {
            this.popoverElement = ref
        },
        target: (ref: HTMLElement) => {
            this.targetElement = ref
        }
    }

    private inTargetOrPopover: boolean

    private popperScheduleUpdate: () => void

    private cancelTimeoutFn: () => void

    constructor(props: IPopoverPops, context?: any) {
        super(props, context);

        this.state = {
            isOpen: this.getOpenState(props),
            transformOrigin: ''
        }
    }

    componentWillReceiveProps(nextProps: IPopoverPops) {
        const isOpen = this.getOpenState(nextProps)
        if (!isUndefined(nextProps.isOpen) && isOpen != this.state.isOpen) {
            this.setState({isOpen})
        }
    }

    private getOpenState(props: IPopoverPops) {
        if (props.disabled) {
            return false
        }
        if (isUndefined(props.isOpen)) {
            return this.props.defaultIsOpen
        }
        return this.props.isOpen
    }

    private elementInPopover(element: HTMLElement) {
        return this.popoverElement && this.popoverElement.contains(element)
    }

    private get isInteractionHoverKind() {
        return this.props.interactionKind == PopperInteractionKind.HOVER ||
            this.props.interactionKind == PopperInteractionKind.HOVER_TARGET
    }

    private realChildren() {
        const {target, content, children} = this.props
        const [targetChild, contentChild] = React.Children.toArray(children)
        return {
            target: isUndefined(target) ? targetChild : target,
            content: isUndefined(content) ? contentChild : content
        }
    }

    private get hasContent() {
        const {content} = this.realChildren()
        return !isUndefined(content)
    }

    private get hasArrow() {
        return !this.props.minimal
    }

    private handleOverlayClose = (event: React.SyntheticEvent<HTMLElement>) => {
        if (!this.targetElement || !this.targetElement.contains(event.target as HTMLElement)) {
            this.setOpenState(false, event)
        }
    }

    private getPopperModifiers() {
        const {modifiers} = this.props
        return {
            ...modifiers,
            updatePopoverState: {
                enabled: true,
                fn: this.updateTransformOrigin,
                order: 900,
            },
        }
    }

    private updateTransformOrigin: ModifierFn = (data: Data) => {
        this.setState({
            transformOrigin: getTransformOrigin(data)
        })
        return data
    }

    public render() {
        const {wrapperTagName, className} = this.props
        return (
            <Manager>
                {React.createElement(wrapperTagName, {
                    className: cn(`${PREFIX}-popover-wrapper`, className)
                }, [
                    <Reference key="reference" innerRef={this.refHandlers.target}>
                        {this.renderTarget}
                    </Reference>,
                    <Overlay
                        key="overlay"
                        usePortal={this.props.usePortal}
                        autoFocus={this.props.autoFocus}
                        backdropProps={this.props.backdropProps}
                        canEscapeKeyClose={this.props.canEscapeKeyClose}
                        canOutsideClickClose={this.props.interactionKind === PopperInteractionKind.CLICK}
                        className={this.props.portalClassName}
                        hasBackdrop={this.props.hasBackdrop}
                        transitionName={`${PREFIX}-popover-transition`}
                        isOpen={this.state.isOpen && this.hasContent}
                        onClose={this.handleOverlayClose}
                        onClosed={this.props.onClosed}
                        onClosing={this.props.onClosing}
                        onOpened={this.props.onOpened}
                        onOpening={this.props.onOpening}
                        transitionDuration={this.props.transitionDuration}
                        portalContainer={this.props.portalContainer}
                    >
                        <Popper
                            placement={positionToPlacement(this.props.position) as Placement}
                            modifiers={this.getPopperModifiers()}
                            innerRef={this.refHandlers.popover}>
                            {this.renderPopper}
                        </Popper>
                    </Overlay>
                ])}
            </Manager>
        )
    }

    private renderTarget = (referenceProps: ReferenceChildrenProps) => {
        const {isOpen} = this.state
        const {target} = this.realChildren()
        const {openOnTargetFocus, targetClassName, targetTagName: TagName} = this.props;
        let targetProps: React.HTMLProps<HTMLElement>
        if (this.isInteractionHoverKind) {
            targetProps = {
                onBlur: this.targetBlurHandler,
                onFocus: this.targetFocusHandler,
                onMouseEnter: this.mouseEnterHandler,
                onMouseLeave: this.mouseLeaveHandler,
            }
        } else {
            targetProps = {
                onClick: this.targetClickHandler
            }
        }
        targetProps.className = cn(`${PREFIX}-popover-target`, {
            [`${PREFIX}-popover-target-open`]: isOpen
        }, targetClassName)
        targetProps.ref = referenceProps.ref
        if (openOnTargetFocus && this.isInteractionHoverKind) {
            targetProps.tabIndex = 0
        }
        return <TagName {...targetProps}>{target}</TagName>
    }

    private renderPopper = (popperProps: PopperChildrenProps) => {
        const hasArrow = this.hasArrow
        const {content} = this.realChildren()
        this.popperScheduleUpdate = popperProps.scheduleUpdate
        const contentProps: React.HTMLProps<HTMLDivElement> = {
            onClick: this.popperHandler
        }
        if (this.isInteractionHoverKind) {
            contentProps.onMouseEnter = this.mouseEnterHandler
            contentProps.onMouseLeave = this.mouseLeaveHandler
        }
        const popperClasses = cn(`${PREFIX}-popover`, {
            [`${PREFIX}-popover-minimal`]: this.props.minimal
        }, this.props.popoverClassName)
        return (
            <div className={`${PREFIX}-popover-transition`}
                 ref={popperProps.ref}
                 data-placement={popperProps.placement}
                 style={popperProps.style}>
                <div className={popperClasses} {...contentProps} style={{transformOrigin: this.state.transformOrigin}}>
                    {hasArrow && <span className={`${PREFIX}-popover-arrow`}
                                       ref={popperProps.arrowProps.ref}
                                       data-placement={popperProps.placement}
                                       style={popperProps.arrowProps.style}/>}
                    <div className={`${PREFIX}-popover-content`}>
                        {content}
                    </div>
                </div>
            </div>
        )
    }

    private popperHandler = (event: React.MouseEvent<HTMLElement>) => {
        const target = event.target as HTMLElement
        const dismissClasses = `.${PREFIX}-popover-dismiss`
        if (target.closest(dismissClasses)) {
            this.setOpenState(false)
        }
    }

    private targetBlurHandler = (event: React.FocusEvent<HTMLElement>) => {
        if (this.props.openOnTargetFocus && this.isInteractionHoverKind) {
            if (!this.elementInPopover(event.relatedTarget as HTMLElement)) {
                this.mouseLeaveHandler(event)
            }
        }
    }

    private targetFocusHandler = (event: React.FocusEvent<HTMLElement>) => {
        if (this.props.openOnTargetFocus && this.isInteractionHoverKind) {
            this.mouseEnterHandler(event)
        }
    }

    private mouseEnterHandler = (event: React.SyntheticEvent<HTMLElement>) => {
        this.inTargetOrPopover = true
        if (this.elementInPopover(event.target as HTMLElement) && this.props.interactionKind == PopperInteractionKind.HOVER_TARGET) {
            this.mouseLeaveHandler(event)
        } else {
            this.setOpenState(true, event, this.props.hoverOpenDelay)
        }
    }

    private mouseLeaveHandler = (event: React.SyntheticEvent<HTMLElement>) => {
        this.inTargetOrPopover = false
        this.setTimeout(() => {
            if (this.inTargetOrPopover) {
                return
            }
            this.setOpenState(false, event, this.props.hoverCloseDelay)
        })
    }

    private targetClickHandler = (event: React.MouseEvent<HTMLElement>) => {
        if (!this.props.disabled && !this.elementInPopover(event.target as HTMLElement)) {
            if (isUndefined(this.props.isOpen)) {
                this.setState(prevState => ({isOpen: !prevState.isOpen}))
            } else {
                this.setOpenState(!this.props.isOpen, event)
            }
        }
    }

    private setOpenState(isOpen: boolean, event?: React.SyntheticEvent<HTMLElement>, timeout?: number) {
        safeInvoke(this.cancelTimeoutFn)
        if (timeout > 0) {
            this.cancelTimeoutFn = this.setTimeout(() => this.setOpenState(isOpen, event), timeout)
        } else {
            if (isUndefined(this.props.isOpen)) {
                this.setState({isOpen})
            } else {
                safeInvoke(this.props.onInteraction, isOpen, event)
            }
            if (!isOpen) {
                safeInvoke(this.props.onClose, event)
            }
        }
    }
}


