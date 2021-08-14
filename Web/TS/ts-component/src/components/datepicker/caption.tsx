import * as React from 'react';
import * as cn from 'classnames'
import * as dateFns from 'date-fns'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {Icon} from "../..";
import {safeInvoke} from "../../common/utils";

export interface ICaptionProps extends IProps {
    date: Date,
    showBar?: boolean,
    decreaseMonth?: () => void,
    increaseMonth?: () => void,
    canDecreaseMonth?: boolean,
    canIncreaseMonth?: boolean
}

export class Caption extends React.Component<ICaptionProps> {
    public static displayName = 'Ts:Caption'

    public static defaultProps = {
        showBar: true,
        canDecreaseMonth: true,
        canIncreaseMonth: true
    }

    private decreaseMonth = () => {
        safeInvoke(this.props.decreaseMonth)
    }

    private increaseMonth = () => {
        safeInvoke(this.props.increaseMonth)
    }

    public render() {
        const {date, showBar, className, canDecreaseMonth, canIncreaseMonth} = this.props
        const captionClasses = cn(`${PREFIX}-date-picker-caption`, className)
        return (
            <div className={captionClasses}>
                {showBar && <Icon
                    title="上个月"
                    name="caret-left"
                    disabled={!canDecreaseMonth}
                    onClick={this.decreaseMonth}/>}
                <div className={`${PREFIX}-date-picker-caption-body`}>
                    {dateFns.getYear(date)}年{dateFns.getMonth(date) + 1}月
                </div>
                {showBar && <Icon
                    title="下个月"
                    name="caret-right"
                    disabled={!canIncreaseMonth}
                    onClick={this.increaseMonth}/>}
            </div>
        )
    }
}
