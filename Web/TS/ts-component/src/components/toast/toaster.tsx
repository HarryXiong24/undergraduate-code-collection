import * as cn from 'classnames'
import * as React from 'react'
import * as ReactDom from 'react-dom'
import {IToastProps, Toast} from "./toast";
import {IProps} from "../../common/props";
import {Overlay, PositionKind} from "../..";
import {AbstractPureComponent} from "../../common/abstractPureComponent";
import {safeInvoke} from "../../common/utils";
import {PREFIX} from "../../common/constants";
import {ESCAPE} from "../../common/keys";

import './toaster.scss'

export type IToastOption = IToastProps & { key?: string }

export interface IToaster {
    show(props: IToastOption, key?: string): string,

    dismiss(key: string): void,

    clear(): void,

    getToasts(): IToastOption[]
}

export interface IToasterProps extends IProps {
    autoFocus?: boolean,
    canEscapeKeyClose?: boolean,
    usePortal?: boolean,
    position?: Partial<PositionKind>
}

export interface IToasterState {
    toasts: IToastOption[]
}

export class Toaster extends AbstractPureComponent<IToasterProps, IToasterState> implements IToaster {
    public static displayName = 'Ts:Toaster'

    public static defaultProps = {
        autoFocus: false,
        canEscapeKeyClose: true,
        usePortal: true,
        position: PositionKind.TOP
    }

    public static create(props: IToasterProps = {...Toaster.defaultProps}, container = document.body) {
        let toaster: Toaster
        const element = document.createElement('div')
        container.appendChild(element)
        ReactDom.render(<Toaster {...props} ref={ref => toaster = ref}/>, element)
        return toaster
    }

    public state = {
        toasts: [] as IToastOption[]
    }

    private toastId: number = 0

    private get isPositionBottom() {
        return this.props.position.indexOf('bottom') != -1
    }

    public show(props: IToastOption, key?: string): string {
        const option = this.createToastOption(props, key)
        if (!key || this.isNewKey(key)) {
            if (this.isPositionBottom) {
                this.setState(prevState => ({toasts: [option, ...prevState.toasts]}))
            } else {
                this.setState(prevState => ({toasts: [...prevState.toasts, option]}))
            }
        } else {
            this.setState(prevState => ({
                toasts: prevState.toasts.map(toast => toast.key == key ? option : toast)
            }))
        }
        return option.key
    }

    public dismiss(key: string, manual = true) {
        this.setState(prevState => ({
            toasts: prevState.toasts.filter(toast => {
                const equal = toast.key == key
                if (equal) {
                    safeInvoke(toast.onDismiss, manual)
                }
                return !equal
            })
        }))
    }

    public clear() {
        this.state.toasts.map(t => safeInvoke(t.onDismiss, true))
        this.setState({toasts: []})
    }

    public getToasts() {
        return this.state.toasts
    }

    private createToastOption(props, key = `toast-${this.toastId++}`) {
        return {...props, key}
    }

    private isNewKey(key: string) {
        return this.state.toasts.every(toast => toast.key != key)
    }

    public render() {
        const toasterClasses = cn(`${PREFIX}-toaster`, this.getPositionClass(), this.props.className)
        return (
            <Overlay autoFocus={this.props.autoFocus}
                     canOutsideClickClose={false}
                     hasBackdrop={false}
                     onClose={this.handleClose}
                     isOpen={!!this.state.toasts.length}
                     usePortal={this.props.usePortal}
                     className={toasterClasses}
                     transitionName={`${PREFIX}-toast-transition`}
                     canEscapeKeyClose={this.props.canEscapeKeyClose}>
                {this.state.toasts.map(this.renderToaster)}
            </Overlay>
        )
    }

    private getPositionClass() {
        return this.props.position.split('-').map(p => `${PREFIX}-toaster-${p}`)
    }

    private renderToaster = (props: IToastOption) => {
        return <Toast {...props} onDismiss={this.getDismissHandler(props)}/>
    }

    private handleClose = (event: React.KeyboardEvent<HTMLElement>) => {
        if (event.which == ESCAPE)
            this.clear()
    }

    private getDismissHandler = (props: IToastOption) => {
        return () => {
            this.dismiss(props.key, false)
        }

    }
}
