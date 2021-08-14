import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {TBound, TColumn} from "./tableType";

export interface ITableHeaderProps extends IProps {
    columns: TColumn[],
    style?: React.CSSProperties,
    bound?: TBound
}

export class TableHeader extends React.PureComponent<ITableHeaderProps> {
    public static displayName = 'Ts:TableHeader'

    public componentDidUpdate() {

    }

    private renderTh = (column: TColumn) => {
        const {bound = {}} = this.props
        const {title, fixed, ...rest} = column
        const thClasses = cn({
            [`${PREFIX}-table-cell-fixed-${fixed}`]: fixed
        })
        return <th className={thClasses} {...rest} style={bound}>{title}</th>
    }

    public render() {
        const {className, columns, style} = this.props
        return (
            <thead className={cn(`${PREFIX}-table-header`, className)}>
            <tr style={style}>
                {columns.map(this.renderTh)}
            </tr>
            </thead>
        )
    }
}
