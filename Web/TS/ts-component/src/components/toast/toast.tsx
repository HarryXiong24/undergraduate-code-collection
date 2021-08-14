import * as cn from 'classnames'
import * as React from 'react'
import {IAppearanceProps, IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {AbstractPureComponent} from "../../common/abstractPureComponent";
import {safeInvoke} from "../../common/utils";
import {Icon} from "../..";

export interface IToastProps extends IProps, IAppearanceProps {
    iconName?: string,
    message: React.ReactNode,
    showDismissButton?: boolean,
    onDismiss?: (manual: boolean) => void,
    duration?: number
}

export class Toast extends AbstractPureComponent<IToastProps, {}> {
    public static displayName = 'Ts:Toast'

    public static defaultProps = {
        duration: 5000,
        showDismissButton: true
    }

    public componentDidMount() {
        this.startTimeout()
    }

    public componentDidUpdate(prevProps: IToastProps) {
        if (!prevProps.duration && this.props.duration) {
            this.startTimeout()
        } else if (prevProps.duration && !this.props.duration) {
            this.clearTimeouts()
        } else if (prevProps.duration != this.props.duration && this.props.duration) {
            this.startTimeout()
        }
    }

    public render() {
        const {className, message, iconName, showDismissButton, type} = this.props
        const toastClasses = cn(`${PREFIX}-toast`, {
            [`${PREFIX}-toast-${type}`]: type
        }, className)
        return (
            <div onMouseEnter={this.clearTimeouts}
                 onMouseLeave={this.startTimeout}
                 className={toastClasses}>
                {iconName && <Icon name={iconName}/>}
                <span className={`${PREFIX}-toast-message`}>{message}</span>
                {showDismissButton && <Icon name="close" onClick={this.handleDismiss}/>}
            </div>
        )
    }

    public startTimeout = () => {
        if (this.props.duration > 0) {
            this.setTimeout(() => {
                this.triggerDismiss(false)
            }, this.props.duration)
        }
    }

    public handleDismiss = () => {
        this.triggerDismiss(true)
    }

    private triggerDismiss(manual: boolean) {
        safeInvoke(this.props.onDismiss, manual)
        this.clearTimeouts()
    }
}
