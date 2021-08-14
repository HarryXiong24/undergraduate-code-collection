import * as React from 'react';
import * as cn from 'classnames'
import * as dateFns from 'date-fns'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {Weeks} from "./weeks";
import {getApproxTimestamp, getWeekArray} from "./datePickerUtil";
import {DayCell} from './dayCell';
import {isUndefined, uuid} from "../../common/utils";
import {IDatePickerProps} from './datePicker';
import {Caption} from "./caption";

export interface IMonthProps extends IDatePickerProps, IProps {
    decreaseMonth?: () => void,
    increaseMonth?: () => void,
    canDecreaseMonth?: boolean,
    canIncreaseMonth?: boolean
}

export class Month extends React.Component<IMonthProps> {
    public static displayName = 'Ts:Month'

    private extendReserveModifier(day: Date) {
        let {modifier, selectedDays, disabledDays} = this.props
        let newModifier = {...modifier}

        if (!isUndefined(selectedDays)) {
            if (Array.isArray(selectedDays) || selectedDays instanceof Date) {
                const selectedArr = Array.isArray(selectedDays) ? selectedDays : [selectedDays]
                newModifier.selected = () => !!selectedArr.find(selectedDay => dateFns.isSameDay(selectedDay, day))
            } else {
                // todo range time
            }
        }
        if (!isUndefined(disabledDays)) {
            if (Array.isArray(disabledDays) || disabledDays instanceof Date) {
                const disabledArr = Array.isArray(disabledDays) ? disabledDays : [disabledDays]
                newModifier.disabled = () => !!disabledArr.find(disabledDay => dateFns.isSameDay(disabledDay, day))
            } else {
                newModifier.disabled = disabledDays
            }
        }
        return newModifier
    }

    private renderDay = (day: Date) => {
        const {
            month,
            onDayClick,
            onDayMouseEnter,
            onDayMouseLeave,
            onDayMouseDown,
            onDayMouseUp,
            onDayKeyDown,
            onDayKeyUp,
            onDayFocus,
            showOutsideDays
        } = this.props

        const modifier = this.extendReserveModifier(day)
        const isToday = dateFns.isToday(day)
        const isOutside = dateFns.getMonth(day) != dateFns.getMonth(month)
        const tabIndex = isOutside ? -1 : 0
        const dayKey = getApproxTimestamp(day)
        const dayValue = dateFns.getDate(day)

        const dayClasses = cn({
            [`${PREFIX}-date-picker-day-today`]: isToday,
            [`${PREFIX}-date-picker-day-outside`]: isOutside
        }, Object.keys(modifier).map(key => ({[`${PREFIX}-date-picker-day-${key}`]: modifier[key](day)})))

        return (
            <DayCell key={dayKey}
                     day={day}
                     empty={!showOutsideDays && isOutside}
                     onClick={onDayClick}
                     onMouseEnter={onDayMouseEnter}
                     onMouseLeave={onDayMouseLeave}
                     onMouseDown={onDayMouseDown}
                     onMouseUp={onDayMouseUp}
                     onKeyDown={onDayKeyDown}
                     onKeyUp={onDayKeyUp}
                     onFocus={onDayFocus}
                     className={dayClasses}
                     tabIndex={tabIndex}>
                {dayValue}
            </DayCell>
        )
    }

    public render() {
        const {
            className,
            showCaption,
            showWeekDays,
            firstDayOfWeek,
            localeWeekDays,
            localeWeekTitles,
            decreaseMonth,
            increaseMonth,
            canDecreaseMonth,
            canIncreaseMonth,
            month
        } = this.props
        const monthClasses = cn(`${PREFIX}-date-picker-month`, className)
        const weekArray = getWeekArray(month, firstDayOfWeek)
        return (
            <div className={monthClasses}>
                {showCaption && <Caption date={month}
                                         canDecreaseMonth={canDecreaseMonth}
                                         canIncreaseMonth={canIncreaseMonth}
                                         increaseMonth={increaseMonth}
                                         decreaseMonth={decreaseMonth}/>}
                {showWeekDays && <Weeks
                    firstDayOfWeek={firstDayOfWeek}
                    localeWeekTitles={localeWeekTitles}
                    localeWeekDays={localeWeekDays}/>
                }
                <div className={`${PREFIX}-date-picker-month-body`}>
                    {weekArray.map(week => {
                        return (
                            <div key={uuid()} className={`${PREFIX}-date-picker-day`}>
                                {week.map(this.renderDay)}
                            </div>
                        )
                    })}
                </div>
            </div>
        )
    }
}
