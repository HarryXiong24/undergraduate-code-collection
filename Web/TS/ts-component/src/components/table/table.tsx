import * as React from 'react'
import * as cn from 'classnames'
import * as objectPath from 'object-path'
import {IProps} from "../../common/props";
import {TBound, TColumn, TRecord} from "./tableType";
import {PREFIX} from "../../common/constants";
import {TableHeader} from "./tableHeader";
import {TableRow} from "./tableRow";
import {isFunction} from "../../common/utils";

import './table.scss'

export interface TTableProps extends IProps {
    data: TRecord[],
    columns: TColumn[],
    onRowClick?: (record, index, event) => void,
    onRowDestroy?: () => void,
    onRowDoubleClick?: (record, index, event) => void,
    showCheckbox?: boolean,
    selectedRowKeys?: any[],
    defaultSelectedRowKeys?: any[],
    selectRowByClick?: boolean,
    expandedRowKeys?: any[]
    defaultExpandedRowKeys?: any[],
    expandRowByClick?: boolean
    useFixedHeader?: boolean,
    showHeader?: boolean,
    style?: React.CSSProperties,
    scroll?: { x?: boolean, y?: boolean },
    emptyText?: React.ReactNode,
    rowKey?: string | number | ((record: TRecord) => string | number)
}

export type ITableState = {
    currentKey: any,
    cellHeights: TBound[],
    scrollStyle: React.CSSProperties,
    scrollPosition: string,
    [key: string]: any
}

export class Table extends React.Component<TTableProps, ITableState> {
    public static displayName = 'Ts:Table'

    public static defaultProps = {
        scroll: {},
        showHeader: true,
        useFixedHeader: false,
        defaultExpandedRowKeys: [],
        defaultSelectedRowKeys: [],
        rowKey: 'key',
        emptyText: '暂无数据',
    }

    private tableRef: HTMLTableElement

    private refHandles = {
        table: (ref: HTMLTableElement) => {
            this.tableRef = ref
        }
    }

    constructor(props: TTableProps, context?: any) {
        super(props, context);

        this.state = {
            currentKey: '',
            cellHeights: [],
            scrollStyle: {},
            scrollPosition: 'left',
            expandedRowKeys: this.props.expandedRowKeys || this.props.defaultExpandedRowKeys,
            selectedRowKeys: this.props.selectedRowKeys || this.props.defaultSelectedRowKeys,
        }
    }

    public componentDidMount() {
        this.updateState()

    }

    private getCellHeights() {
        const rows = Array.from(this.tableRef.querySelectorAll('tr'))
        const cellHeights = []
        rows.forEach(row => {
            const target = Array.from(row.childNodes).map((node: HTMLElement) => ({
                height: node.clientHeight
            })).sort((a, b) => b.height - a.height)[0]
            cellHeights.push({height: target.height})
        })
        return cellHeights
    }

    private getScrollStyle() {
        const rows = Array.from(this.tableRef.querySelectorAll('tr'))
        const startRow = rows[0]
        const scrollStyle: React.CSSProperties = {}
        scrollStyle.marginLeft = Array.from((startRow as HTMLElement)
            .querySelectorAll(`.${PREFIX}-table-cell-fixed-left`))
            .reduce(((total, current) => total += current.clientWidth), 0)
        scrollStyle.marginRight = Array.from((startRow as HTMLElement)
            .querySelectorAll(`.${PREFIX}-table-cell-fixed-right`))
            .reduce(((total, current) => total += current.clientWidth), 0)
        return scrollStyle
    }

    private updateState() {
        this.setState({cellHeights: this.getCellHeights(), scrollStyle: this.getScrollStyle()})
    }

    private handleScroll = (event: React.UIEvent) => {
        const target = event.target as HTMLElement
        if (target.scrollLeft == 0) {
            this.setState({scrollPosition: 'left'})
        } else if (target.getBoundingClientRect().width + target.scrollLeft + 1 >= target.children[0].getBoundingClientRect().width) {
            this.setState({scrollPosition: 'right'})
        } else {
            this.setState({scrollPosition: 'center'})
        }
    }

    private handleHover = (flag: boolean, key: any) => {
        this.setState({currentKey: flag ? key : ''})
    }

    private getRowKey = (record, index) => {
        const {rowKey} = this.props
        if (isFunction(rowKey)) {
            return (rowKey as Function)(record)
        }
        return objectPath.get(record, rowKey, index)
    }

    private renderTHEAD() {
        const {columns} = this.props
        const {cellHeights} = this.state
        return <TableHeader bound={cellHeights[0]} columns={columns}/>
    }

    private renderTBODY() {
        const {columns, data} = this.props
        const {cellHeights, currentKey} = this.state
        return (
            <tbody className={`${PREFIX}-table-body`}>
            {data.map((record, index) => (
                <TableRow
                    onHover={this.handleHover}
                    bound={cellHeights[index + 1]}
                    key={this.getRowKey(record, index)}
                    hoverKey={this.getRowKey(record, index)}
                    className={currentKey && this.getRowKey(record, index) && this.getRowKey(record, index) == currentKey && `${PREFIX}-table-row-hover`}
                    columns={columns}
                    record={record}
                    index={index}/>
            ))}
            </tbody>
        )
    }

    public render() {
        const {className, showHeader, style} = this.props
        const {scrollStyle, scrollPosition} = this.state
        const tableClasses = cn(`${PREFIX}-table`, className)
        return (
            <div className={cn(`${PREFIX}-table-position`, `${PREFIX}-table-position-${scrollPosition}`)} style={style}>
                <div className={`${PREFIX}-table-scroll`} style={scrollStyle} onScroll={this.handleScroll}>
                    <table className={tableClasses} ref={this.refHandles.table}>
                        {showHeader && this.renderTHEAD()}
                        {this.renderTBODY()}
                    </table>
                </div>
            </div>
        )
    }
}
