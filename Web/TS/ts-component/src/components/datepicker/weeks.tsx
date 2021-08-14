import * as React from 'react';
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {AbstractPureComponent} from "../../common/abstractPureComponent";
import {PREFIX} from "../../common/constants";
import {IWeekProps, WeekCell} from "./weekCell";

export interface IWeeksProps extends IProps {
    firstDayOfWeek: number,
    localeWeekDays: [],
    localeWeekTitles: []
}

export class Weeks extends AbstractPureComponent<IWeeksProps> {
    public static displayName = 'Ts:Week'

    public render() {
        const {className, firstDayOfWeek, localeWeekDays, localeWeekTitles} = this.props
        const weekList: IWeekProps[] = []
        for (let i = 0; i < 7; i++) {
            weekList.push({
                weekDay: (i + firstDayOfWeek) % 7,
                localeWeekDays,
                localeWeekTitles
            })
        }
        return (
            <div className={cn(`${PREFIX}-date-picker-week`, className)}>
                {weekList.map((props, i) => <WeekCell key={i} {...props}/>)}
            </div>
        )
    }
}
