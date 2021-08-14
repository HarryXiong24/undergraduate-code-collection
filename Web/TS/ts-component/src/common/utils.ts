import * as React from 'react'

export function shadowClone<T>(target: T): T {
    const source:any = {}
    for(let key in target) {
        if(target.hasOwnProperty(key)) {
            source[key] = (<any>target)[key]
        }
    }
    return source as T
}

export function removeProps<T, P extends T>(props: P, fields: string[]): T {
    const target = shadowClone(props)
    fields.forEach(field => {
        delete target[field]
    })
    return target
}

export function isFunction(value: any) {
    return typeof value == 'function'
}

export function isUndefined(value: any) {
    return value == undefined || value == null
}

export function safeInvoke(func: Function, ...args: any[]) {
    if(isFunction(func)) {
        return func(...args)
    }
}

export function clamp(val: number, min: number, max: number) {
    if(min > max) {
        throw new Error('clamp: max not more less than min')
    }
    return Math.min(Math.max(val, min), max)
}

export function approxEqual(a: number, b: number, tolerance = 0.00001) {
    return Math.abs(a - b) <= tolerance
}

export function uuid() {
    return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g,  (c) => {
        let r = Math.random() * 16 | 0
        let v = c == 'x' ? r : ((r & 0x3) | 0x8)
        return v.toString(16)
    })
}

export const ensureElement = (child: React.ReactChild, tagName: keyof JSX.IntrinsicElements = 'span') => {
    if(isUndefined(child)) {
        return undefined
    }
    if(typeof child == 'string') {
        return child.trim().length ? React.createElement(tagName, {}, child) : undefined
    } else if(typeof child == 'number') {
        return React.createElement(tagName, {}, child)
    } else {
        return child
    }
}


