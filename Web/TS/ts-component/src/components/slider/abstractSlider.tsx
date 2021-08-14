import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {approxEqual, isFunction} from "../../common/utils";
import {PREFIX} from "../../common/constants";

export interface IAbstractSliderProps extends IProps {
    disabled?: boolean,
    labelStepSize?: number,
    min?: number,
    max?: number,
    stepSize?: number,
    showTrackFill?: boolean,
    renderLabel?: ((value: number) => string | number | JSX.Element) | boolean
}

export interface IAbstractSliderState {
    tickSize: number
}

export abstract class AbstractSlider<P extends IAbstractSliderProps> extends React.Component<P, IAbstractSliderState> {
    public state: IAbstractSliderState = {
        tickSize: 0,
    }

    private trackElement: HTMLElement

    protected abstract renderHandlers(): JSX.Element | JSX.Element[]
    protected abstract renderFill(): JSX.Element
    protected abstract handleTrackClick(event: MouseEvent | React.MouseEvent<HTMLElement>): void

    protected formatLabel(value: number): React.ReactChild {
        const { renderLabel } = this.props
        if(renderLabel === false) {
            return null
        } else if(isFunction(renderLabel)) {
            return (renderLabel as Function)(value)
        } else {
            return value
        }
    }

    private trackRef = (ref: HTMLElement) => {
        this.trackElement = ref
    }

    public render() {
        const classes = cn(`${PREFIX}-slider`, {
            [`${PREFIX}-slider-disabled`]: this.props.disabled
        }, this.props.className)
        return (
            <div className={classes} onMouseDown={this.maybeHandleTrackClick}>
                <div className={`${PREFIX}-slider-track`} ref={this.trackRef}>
                    {this.maybeRenderTrackFill()}
                </div>
                {this.maybeRenderAxis()}
                {this.renderHandlers()}
            </div>
        )
    }

    private maybeRenderTrackFill() {
        if (this.props.showTrackFill && this.trackElement) {
            return this.renderFill()
        }
        return null
    }

    private maybeRenderAxis() {
        const { min, max, labelStepSize } = this.props
        if(this.props.renderLabel === false) {
            return null
        }
        const stepSize = Math.round(this.state.tickSize * labelStepSize)
        const labels: JSX.Element[] = []
        for(let i = min, left = 0; i < max || approxEqual(i, max); left += stepSize, i += labelStepSize) {
            labels.push(<span className={`${PREFIX}-slider-axis-label`} key={i} style={{left}}>{this.formatLabel(i)}</span>)
        }
        return (<div className={`${PREFIX}-slider-axis`}>{labels}</div>)
    }

    private maybeHandleTrackClick = (event: React.MouseEvent<HTMLElement>) => {
        const target = event.target as HTMLElement
        if (!this.props.disabled && !target.closest(`.${PREFIX}-slider-handler`)) {
            this.handleTrackClick(event.nativeEvent as MouseEvent)
        }
    }

    public componentDidMount() {
        this.updateTickSize()
    }

    private updateTickSize() {
        if (this.trackElement != null) {
            const tickSize = this.trackElement.clientWidth / (this.props.max - this.props.min)
            this.setState({tickSize})
        }
    }
}
