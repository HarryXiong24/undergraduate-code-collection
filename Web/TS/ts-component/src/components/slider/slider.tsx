import * as React from 'react'
import {AbstractSlider, IAbstractSliderProps} from "./abstractSlider";
import {Handler, IHandlerProps} from "./handler";
import {PREFIX} from "../../common/constants";

import './slider.scss'

export interface ISliderProps extends IAbstractSliderProps {
    value?: number,
    onChange?: (value: number) => void,
    onRelease?: (value: number) => void
}

export class Slider extends AbstractSlider<ISliderProps> {
    public static readonly displayName = 'Ts:Slider'

    public static defaultProps: ISliderProps = {
        disabled: false,
        min: 0,
        max: 10,
        value: 0,
        showTrackFill: true,
        stepSize: 1
    }

    private handler: Handler

    private handlerRef = (ref: Handler) => {
        this.handler = ref as Handler
    }

    protected renderHandlers() {
        return (
            <Handler
                {...(this.props as IHandlerProps)}
                {...this.state}
                className={''}
                label={this.formatLabel(this.props.value)}
                ref={this.handlerRef}
            />
        )
    }

    protected renderFill() {
        const styles = {
            width: this.props.value * this.state.tickSize
        }
        return (
            <div className={`${PREFIX}-slider-track-process`} style={styles} />
        )
    }

    protected handleTrackClick(event: React.MouseEvent<HTMLElement>) {
        if (this.handler != null) {
            this.handler.changeValue(this.handler.clientToValue(event.clientX))
        }
    }
}
