import * as React from 'react'
import * as cn from 'classnames'
import * as objectPath from 'object-path'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {TCell, TColumn, TRecord} from "./tableType";

export interface ITableCellProps extends IProps {
    column: TColumn,
    record: TRecord,
    index: number,
    style?: React.CSSProperties
}

export class TableCell extends React.Component<ITableCellProps> {
    public static displayName = 'Ts:TableCell'

    private static isValidateRenderCellText(text) {
        return text && !React.isValidElement(text) && typeof text == 'object'
    }

    public render() {
        const {column, record, index, className, style} = this.props
        const {field, render, fixed} = column
        let text = objectPath.get(record, field)
        let tdProps
        let tdRowSpan
        let tdColSpan
        if (render) {
            text = render(text, record, index)
            if (TableCell.isValidateRenderCellText(text)) {
                tdProps = (text as TCell).props
                tdRowSpan = tdProps.colSpan
                tdColSpan = tdProps.rowSpan
                text = (text as TCell).children
            }
        }
        const tdClasses = cn(`${PREFIX}-table-cell`, {
            [`${PREFIX}-table-cell-fixed-${fixed}`]: fixed
        }, className)

        return (
            <td className={tdClasses}
                style={style}
                rowSpan={tdRowSpan}
                colSpan={tdColSpan}>
                {text}
            </td>
        )
    }
}
