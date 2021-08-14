import * as React from 'react'
import * as cn from 'classnames'
import {IOverlayProps, Overlay} from "../overlay/overlay";
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {Icon} from "../icon/icon";

import './dialog.scss'

export interface IDialogProps extends IOverlayProps, IProps {
    iconName?: string,
    isCloseButtonShow?: boolean,
    title?: React.ReactNode,
}

/**
 * icon 待完善
 */
export class Dialog extends React.Component<IDialogProps> {
    public static readonly displayName = 'Ts:Dialog'

    public static defaultProps = {
        hasBackdrop: true,
        canOutsideClickClose: true,
        isOpen: false,
        isCloseButtonShow: true
    }

    public render() {
        const {className, children, ...rest} = this.props
        return (
            <Overlay {...rest} className={`${PREFIX}-overlay-dialog`}>
                <div className={`${PREFIX}-dialog`}>
                    <div className={cn(`${PREFIX}-dialog-content`, className)}>
                        {this.maybeRenderHeader()}
                        {children}
                    </div>
                </div>
            </Overlay>
        )
    }

    public maybeRenderHeader() {
        if(this.props.title) {
            return (
                <div className={`${PREFIX}-dialog-header`}>
                    {this.maybeRenderIcon()}
                    <h4 className={`${PREFIX}-dialog-header-title`}>{this.props.title}</h4>
                    {this.maybeRenderCloseButton()}
                </div>
            )
        }
        return null
    }

    public maybeRenderIcon() {
        if(this.props.iconName) {
            return <Icon name={this.props.iconName}/>
        }
        return null
    }

    public maybeRenderCloseButton() {
        if(this.props.isCloseButtonShow) {
            return <Icon name="close" onClick={this.props.onClose}/>
        }
        return null
    }
}
