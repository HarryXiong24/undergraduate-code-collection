import * as React from 'react';
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {AbstractPureComponent} from "../../common/abstractPureComponent";
import {PREFIX} from "../../common/constants";
import {DayHandler} from './datePickerUtil';
import {safeInvoke} from "../../common/utils";

export interface IDayProps extends IProps {
    day?: Date
    empty?: boolean,
    onClick?: DayHandler,
    onMouseEnter?: DayHandler,
    onMouseLeave?: DayHandler,
    onMouseDown?: DayHandler,
    onMouseUp?: DayHandler,
    onKeyDown?: DayHandler,
    onKeyUp?: DayHandler,
    onFocus?: DayHandler,
    tabIndex?: number
}

export class DayCell extends AbstractPureComponent<IDayProps, {}> {
    public static displayName = 'Ts:DayCell'

    public static defaultProps = {
        empty: false
    }

    private wrapHandler = (handler: DayHandler, day: Date) => {
        return (event: React.SyntheticEvent) => {
            event.persist()
            safeInvoke(handler, day, event)
        }
    }

    public render() {
        const {
            day,
            empty,
            onClick,
            onMouseEnter,
            onMouseLeave,
            onMouseDown,
            onMouseUp,
            onKeyDown,
            onKeyUp,
            onFocus,
            children,
            className,
            tabIndex
        } = this.props
        const dayClasses = cn(`${PREFIX}-date-picker-day-cell`, className)
        if (empty) {
            return <div tabIndex={tabIndex} className={dayClasses}/>
        }
        return (
            <div tabIndex={tabIndex}
                 className={dayClasses}
                 onMouseEnter={this.wrapHandler(onMouseEnter, day)}
                 onMouseLeave={this.wrapHandler(onMouseLeave, day)}
                 onMouseDown={this.wrapHandler(onMouseDown, day)}
                 onMouseUp={this.wrapHandler(onMouseUp, day)}
                 onKeyDown={this.wrapHandler(onKeyDown, day)}
                 onKeyUp={this.wrapHandler(onKeyUp, day)}
                 onFocus={this.wrapHandler(onFocus, day)}
                 onClick={this.wrapHandler(onClick, day)}>
                {children}
            </div>
        )
    }
}

