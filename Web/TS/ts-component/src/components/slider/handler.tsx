import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {clamp, safeInvoke} from "../../common/utils";
import {PREFIX} from "../../common/constants";
import {ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT, ARROW_UP} from "../../common/keys";

export interface IHandlerProps extends IProps {
    disabled?: boolean
    label: React.ReactChild,
    min: number,
    max: number,
    value: number,
    stepSize: number,
    tickSize: number,
    onChange?: (value: number) => void,
    onRelease?: (value: number) => void
}

export interface IHandlerState {
    isMoving: boolean,
    handlerSize: number
}

export class Handler extends React.Component<IHandlerProps, IHandlerState> {
    public static readonly displayName = 'Ts:SliderHandler'

    public state: IHandlerState = {
        isMoving: false,
        handlerSize: 0
    }

    private handlerElement: HTMLSpanElement

    private handlerRef = (ref: HTMLSpanElement) => {
        this.handlerElement = ref
        const handlerSize = ref.getBoundingClientRect().height
        this.setState({
            handlerSize
        })
    }

    public render() {
        const {isMoving, handlerSize} = this.state
        const {min, value, tickSize} = this.props
        const classes = cn(`${PREFIX}-slider-handler`, {
            [`${PREFIX}-slider-handler-active`]: isMoving
        })
        const styles = {
            left: (value - min) * tickSize - handlerSize / 2
        }
        return (
            <span
                className={classes}
                style={styles}
                onKeyDown={this.handleKeyDown}
                onKeyUp={this.handleKeyUp}
                onMouseDown={this.handleMouseDown}
                ref={this.handlerRef}
                tabIndex={0}
            >
                {this.maybeRenderLabel()}
            </span>
        )
    }

    private maybeRenderLabel() {
        if (this.props.label != null) {
            return (
                <span className={`${PREFIX}-slider-handler-label`}>{this.props.label}</span>
            )
        }
        return null
    }

    private handleKeyDown = (event: React.KeyboardEvent<HTMLSpanElement>) => {
        if (!this.props.disabled) {
            if (event.which == ARROW_LEFT || event.which == ARROW_UP) {
                this.changeValue(this.props.value - this.props.stepSize)
                event.preventDefault();
            } else if (event.which == ARROW_RIGHT || event.which == ARROW_DOWN) {
                this.changeValue(this.props.value + this.props.stepSize)
                event.preventDefault();
            }
        }
    }

    private handleKeyUp = (event: React.KeyboardEvent<HTMLSpanElement>) => {
        const matchKeys = [ARROW_DOWN, ARROW_UP, ARROW_LEFT, ARROW_RIGHT]
        if (matchKeys.indexOf(event.which) != -1) {
            safeInvoke(this.props.onRelease, this.props.value);
        }
    }

    private handleMouseDown = (event: MouseEvent | React.MouseEvent<HTMLElement>) => {
        this.addDocumentListeners()
        this.setState({
            isMoving: true
        })
        this.changeValue(this.clientToValue(event.clientX))
        event.preventDefault();
    }

    private handleMouseMove = (event: MouseEvent) => {
        if (this.state.isMoving && !this.props.disabled) {
            this.changeValue(this.clientToValue(event.clientX))
        }
    }

    private handleMouseUp = (event: MouseEvent) => {
        this.removeDocumentListeners()
        this.setState({
            isMoving: false
        })
        const finalValue = this.clamp(this.clientToValue(event.clientX))
        safeInvoke(this.props.onRelease, finalValue)
    }

    public changeValue(newValue: number) {
        newValue = this.clamp(newValue)
        if (newValue != this.props.value) {
            safeInvoke(this.props.onChange, newValue)
        }
    }

    private clamp(value: number) {
        return clamp(value, this.props.min, this.props.max)
    }

    public clientToValue(clientPixel: number) {
        const {value, stepSize, tickSize} = this.props
        if (this.handlerElement == null) {
            return value
        }
        const rect = this.handlerElement.getBoundingClientRect()
        const centerPixel = rect.left + rect.width / 2
        const delta = Math.round((clientPixel - centerPixel) / (tickSize * stepSize)) * stepSize
        return value + delta
    }

    public componentWillUnmount() {
        this.removeDocumentListeners()
    }

    private addDocumentListeners() {
        document.addEventListener("mousemove", this.handleMouseMove);
        document.addEventListener("mouseup", this.handleMouseUp);
    }

    private removeDocumentListeners() {
        document.removeEventListener("mousemove", this.handleMouseMove);
        document.removeEventListener("mouseup", this.handleMouseUp);
    }
}
