import * as React from 'react';
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {AbstractPureComponent} from "../../common/abstractPureComponent";
import {PREFIX} from "../../common/constants";

export interface IWeekProps extends IProps {
    weekDay: number,
    localeWeekDays: [],
    localeWeekTitles: []
}

export class WeekCell extends AbstractPureComponent<IWeekProps> {
    public static displayName = 'Ts:WeekCell'

    public render() {
        const {weekDay, className, localeWeekDays, localeWeekTitles} = this.props
        return (
            <div className={cn(`${PREFIX}-date-picker-week-cell`, className)}>
                <span title={localeWeekTitles[weekDay]}>{localeWeekDays[weekDay]}</span>
            </div>
        )
    }
}
