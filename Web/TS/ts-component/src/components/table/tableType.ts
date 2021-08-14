import * as React from 'react'

export type TBound = {
    width?: number,
    height?: number
}

export type TCell = {
    props?: React.ComponentProps<any>,
    children?: React.ReactNode,
    [key: string]: any
}

export type TColumn = {
    fixed?: string,
    field: string,
    title: React.ReactNode,
    render?: (text: any, record: TRecord, index: number) => React.ReactNode | TCell,
    width?: string | number,
    [key: string]: any
}

export type TRecord = {
    [key: string]: any
}
