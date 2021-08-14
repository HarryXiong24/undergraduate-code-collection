import * as React from 'react';
import * as dateFns from 'date-fns'

export type DayHandler = (day: Date, event: React.SyntheticEvent) => void

export type Modifier = {
    [key: string]: (date: Date) => boolean
}

export const getApproxTimestamp = (date: Date) => {
    return `${date.getFullYear()}:${date.getMonth()}:${date.getDate()}`
}

export const cloneDate = (date: Date) => {
    return new Date(date.getTime())
}

export const getWeekArray = (date: Date, firstDayOfWeek: number): Date[][] => {
    const daysInMonth = dateFns.getDaysInMonth(date)
    const dayArray: Date[] = []

    for (let i = 1; i <= daysInMonth; i++) {
        dayArray.push(new Date(date.getFullYear(), date.getMonth(), i, 12))
    }

    const startOfMonth = dateFns.startOfMonth(date)
    const endOfMonth = dateFns.endOfMonth(date)
    const startDayOfWeek = dateFns.getDay(startOfMonth) + firstDayOfWeek
    const endDayOfWeek = dateFns.getDay(endOfMonth) + firstDayOfWeek

    for (let j = 1; j <= startDayOfWeek; j++) {
        dayArray.unshift(dateFns.subDays(startOfMonth, j))
    }

    for (let k = 1; k <= 7 - (endDayOfWeek + 1); k++) {
        dayArray.push(dateFns.addDays(endOfMonth, k))
    }

    let start = 0
    const span = 7
    const total = Math.ceil(dayArray.length / span)
    const weekArray: Date[][] = []
    while (start < total) {
        weekArray.push(dayArray.slice(start * 7, start * span + span));
        start += 1;
    }

    if(start == 5) {
        const weekExtra = []
        const startDay = dayArray[dayArray.length - 1]
        for(let l = 1; l <= 7; l++) {
            weekExtra.push(dateFns.addDays(startDay, l))
        }
        weekArray.push(weekExtra)
    }
    
    return weekArray
}
