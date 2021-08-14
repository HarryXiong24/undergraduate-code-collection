import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {TBound, TColumn, TRecord} from "./tableType";
import {safeInvoke, uuid} from "../../common/utils";
import {PREFIX} from "../../common/constants";
import {TableCell} from './tableCell';

export interface ITableRowProps extends IProps {
    hoverKey: any,
    onHover?: (flag: boolean, key: any, event?) => void,
    onRowClick?: (record, index, event) => void,
    onRowDestroy?: () => void,
    onRowDoubleClick?: (record, index, event) => void,
    columns: TColumn[],
    record: TRecord,
    visible?: boolean,
    indent?: number,
    index: number,
    expanded?: boolean,
    onExpand?: (expanded: boolean, record: TRecord) => void,
    selected?: boolean,
    onSelect?: (selected: boolean, record: TRecord) => void,
    expandRowByClick?: boolean
    selectRowByClick?: boolean,
    bound?: TBound
}

export class TableRow extends React.Component<ITableRowProps> {
    public static displayName = 'Ts:TableRow'

    public static defaultProps = {
        indent: 0,
        expanded: false,
        selected: false,
        expandRowByClick: false,
        selectRowByClick: false,
        visible: true
    }

    public componentWillUnmount() {
        const {record, index, onRowDestroy} = this.props
        safeInvoke(onRowDestroy, record, index, event)
    }

    private onRowClick = (event: React.SyntheticEvent) => {
        const {record, index, expanded, onExpand, expandRowByClick, onRowClick} = this.props
        if (expandRowByClick) {
            safeInvoke(onExpand, !expanded, record)
        }
        safeInvoke(onRowClick, record, index, event)
    }

    private onRowDoubleClick = () => {
        const {record, index, onRowDoubleClick} = this.props
        safeInvoke(onRowDoubleClick, record, index, event)
    }

    private onMouseEnter = (event: React.SyntheticEvent) => {
        const {hoverKey, onHover} = this.props
        safeInvoke(onHover, true, hoverKey, event)
    }

    private onMouseLeave = (event: React.SyntheticEvent) => {
        const {hoverKey, onHover} = this.props
        safeInvoke(onHover, false, hoverKey, event)
    }

    public render() {
        const {index, columns, record, indent, className, bound} = this.props
        const rowClasses = cn(`${PREFIX}-table-row`, `${PREFIX}-table-level-${indent}`, className)
        return (
            <tr className={rowClasses}
                onMouseEnter={this.onMouseEnter}
                onMouseLeave={this.onMouseLeave}
                onClick={this.onRowClick}
                onDoubleClick={this.onRowDoubleClick}>
                {columns.map(column => (
                    <TableCell key={uuid()}
                               style={{...bound, width: column.width}}
                               index={index}
                               column={column}
                               record={record} />
                ))}
            </tr>
        )
    }
}

