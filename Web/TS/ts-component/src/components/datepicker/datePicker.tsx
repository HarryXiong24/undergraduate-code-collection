import * as React from 'react';
import * as cn from 'classnames'
import * as dateFns from 'date-fns'
import {Month} from "./month";
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {DayHandler, Modifier} from "./datePickerUtil";
import {isUndefined, safeInvoke} from "../../common/utils";

import './datepicker.scss'

/**
 * temporary not support accessibility
 */
export interface IDatePickerProps extends IProps {
    month?: Date,
    fromMonth?: Date,
    toMonth?: Date,
    showOutsideDays?: boolean,
    showCaption?: boolean,
    showWeekDays?: boolean,
    firstDayOfWeek?: number,
    localeWeekDays?: [],
    localeWeekTitles?: [],
    modifier?: Modifier,
    selectedDays?: Date | Date[] | Modifier,
    disabledDays?: Date | Date[] | ((day: Date) => boolean),
    onDayClick?: DayHandler,
    onDayMouseEnter?: DayHandler,
    onDayMouseLeave?: DayHandler,
    onDayMouseDown?: DayHandler,
    onDayMouseUp?: DayHandler,
    onDayKeyDown?: DayHandler,
    onDayKeyUp?: DayHandler,
    onDayFocus?: DayHandler,
    onMonthChange?: (month: Date) => void
}

export interface IDatePickerState {
    currentMonth: Date
}

export class DatePicker extends React.Component<IDatePickerProps, IDatePickerState> {
    public static displayName = 'Ts:DatePicker'

    public static defaultProps = {
        month: new Date(),
        modifier: {},
        showOutsideDays: true,
        showCaption: true,
        showWeekDays: true,
        firstDayOfWeek: 0,
        localeWeekDays: ['日', '一', '二', '三', '四', '五', '六'],
        localeWeekTitles: ['周日', '周一', '周二', '周三', '周四', '周五', '周六']
    }

    constructor(props: IDatePickerProps, context: any) {
        super(props, context)
        this.state = {
            currentMonth: DatePicker.getCurrentMonth(this.props)
        }
    }

    private static getCurrentMonth(props: IDatePickerProps) {
        const {month, fromMonth, toMonth} = props
        let currentMonth = month
        if (!isUndefined(fromMonth) && dateFns.isBefore(month, fromMonth)) {
            currentMonth = fromMonth
        }
        if (!isUndefined(toMonth) && dateFns.isAfter(month, toMonth)) {
            currentMonth = toMonth
        }
        return currentMonth
    }

    public componentWillReceiveProps(nextProps: IDatePickerProps) {
        if(!dateFns.isSameDay(nextProps.month, this.props.month)) {
            this.setState({
                currentMonth: DatePicker.getCurrentMonth(nextProps)
            })
        }
    }

    private get canDecreaseMonth() {
        const prevMonth = dateFns.subMonths(this.state.currentMonth, 1)
        return this.canChangeMonth(prevMonth)
    }

    private get canIncreaseMonth() {
        const nextMonth = dateFns.addMonths(this.state.currentMonth, 1)
        return this.canChangeMonth(nextMonth)
    }

    private canChangeMonth(month: Date) {
        const {fromMonth, toMonth} = this.props
        if (fromMonth && dateFns.differenceInCalendarMonths(fromMonth, month) > 0) {
            return false
        } else if (toMonth && dateFns.differenceInCalendarMonths(toMonth, month) < 0) {
            return false
        }
        return true
    }

    private decreaseMonth = () => {
        if (this.canDecreaseMonth) {
            const prevMonth = dateFns.subMonths(this.state.currentMonth, 1)
            this.setState({
                currentMonth: prevMonth
            }, () => {
                safeInvoke(this.props.onMonthChange, this.state.currentMonth)
            })
        }
    }

    private increaseMonth = () => {
        if (this.canIncreaseMonth) {
            const nextMonth = dateFns.addMonths(this.state.currentMonth, 1)
            this.setState({
                currentMonth: nextMonth
            }, () => {
                safeInvoke(this.props.onMonthChange, this.state.currentMonth)
            })
        }
    }

    public render() {
        return (
            <div className={cn(`${PREFIX}-date-picker`, this.props.className)}>
                <Month {...this.props}
                       decreaseMonth={this.decreaseMonth}
                       increaseMonth={this.increaseMonth}
                       canDecreaseMonth={this.canDecreaseMonth}
                       canIncreaseMonth={this.canIncreaseMonth}
                       month={this.state.currentMonth}/>
            </div>
        )
    }
}
