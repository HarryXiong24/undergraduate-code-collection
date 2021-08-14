import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {safeInvoke, uuid} from "../../common/utils";
import {PREFIX} from "../../common/constants";
import {Icon} from "../icon/icon";
import {OrderKind} from "../../common/kinds";

import './pagination.scss'

export interface IPaginationProps extends IProps {
    disabled?: boolean,
    totalRecords: number,
    pageNeighbors?: number
    pageNum?: number,
    pageSize?: number,
    onChange?: (page: number) => void,
    order?: OrderKind
}

const PREV = 'PREV'
const NEXT = 'NEXT'

export class Pagination extends React.Component<IPaginationProps> {
    public static displayName = 'Ts:Pagination'

    public static defaultProps = {
        disabled: false,
        pageNum: 1,
        pageSize: 20,
        pageNeighbors: 1,
        order: OrderKind.LEFT
    }

    private gotoPage = (page) => {
        const {totalRecords, pageSize, onChange} = this.props
        const totalPages = Math.ceil(totalRecords / pageSize)
        const realPage = Math.max(0, Math.min(page, totalPages))
        if (this.props.pageNum != realPage) {
            safeInvoke(onChange, realPage)
        }
    }

    private handleClick = (page, event: React.MouseEvent<HTMLLIElement>) => {
        event.preventDefault()
        this.gotoPage(page)
    }

    private gotoPrev = (event: React.MouseEvent<HTMLLIElement>) => {
        const {pageNum, pageNeighbors} = this.props
        event.preventDefault()
        this.gotoPage(pageNum - (pageNeighbors * 2 + 1))
    }

    private gotoNext = (event: React.MouseEvent<HTMLLIElement>) => {
        const {pageNum, pageNeighbors} = this.props
        event.preventDefault()
        this.gotoPage(pageNum + (pageNeighbors * 2 + 1))
    }

    private static rangePages(from, to, step = 1) {
        const pages = []
        while (from <= to) {
            pages.push(from)
            from += step
        }
        return pages
    }

    private buildPages() {
        const {totalRecords, pageNum, pageSize, pageNeighbors} = this.props
        const totalPages = Math.ceil(totalRecords / pageSize)
        const totalNum = pageNeighbors * 2 + 1 + 2
        const totalBlock = totalNum + 2
        if (totalPages > totalBlock) {
            const leftBound = pageNum - pageNeighbors
            const rightBound = pageNum + pageNeighbors
            const startPage = leftBound > 2 ? leftBound : 2
            const endPage = rightBound > totalPages - 1 ? totalPages - 1 : rightBound
            let pages = Pagination.rangePages(startPage, endPage)
            let addPrev = startPage > 2
            let addNext = endPage < totalPages - 1
            if (addPrev && !addNext) {
                // ( ]
                const addons = Pagination.rangePages(startPage - (totalNum - 1 - pages.length), startPage - 1)
                pages = [PREV, ...addons, ...pages]
            } else if (!addPrev && addNext) {
                // [ )
                const addons = Pagination.rangePages(endPage + 1, endPage + (totalNum - 1 - pages.length))
                pages = [...pages, ...addons, NEXT]
            } else if (addPrev && addNext) {
                pages = [PREV, ...pages, NEXT]
            }
            return [1, ...pages, totalPages]
        }
        return Pagination.rangePages(1, totalPages)

    }

    public render() {
        const {order, className} = this.props
        const paginationClasses = cn(`${PREFIX}-pagination`, {
            [`${PREFIX}-pagination-${order}`]: order,
        }, className)
        const pages = this.buildPages()
        return (
            <nav>
                <ul className={paginationClasses}>
                    {pages.map(page => this.renderPaginationItem(page))}
                </ul>
            </nav>
        )
    }

    private renderPaginationItem(page) {
        const {disabled, pageNum} = this.props
        const paginationItemClasses = cn(`${PREFIX}-pagination-item`, {
            [`${PREFIX}-pagination-item-disabled`]: disabled,
            [`${PREFIX}-pagination-item-active`]: pageNum == page,
        })
        const handler = page == PREV ? this.gotoPrev : page == NEXT ? this.gotoNext : (event) => this.handleClick(page, event)
        return (
            <li key={uuid()} className={paginationItemClasses} onClick={handler}>
                {page == PREV && <Icon name='double-arrow-left'/>}
                {page == NEXT && <Icon name='double-arrow-right'/>}
                {page != PREV && page != NEXT && page}
            </li>
        )
    }
}
