import React, { useState, useLayoutEffect, useRef } from 'react'
import * as cn from 'classnames'
import { animations } from './preset'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";

import './preset.scss'

export interface IEmphasisProps extends IProps {
    children?: React.ReactNode,
    duration?: number,
    animationIn?: string,
    animationOut?: string,
    style?: React.CSSProperties
}

export enum Animation {
    NONE,
    IN,
    OUT
}

export const Emphasis = (props: IEmphasisProps) => {
    const {children, duration, animationIn, animationOut, style, className} = props
    const [animation, setAnimation] = useState(Animation.NONE)
    const [displayContent, setDisplayContent] = useState(children)
    const firstUpdate = useRef(true)

    useLayoutEffect(() => {
        if(firstUpdate.current) {
            firstUpdate.current = false
            return
        }
        setAnimation(Animation.OUT)
        const timer = setTimeout(() => {
            setAnimation(Animation.IN)
            setDisplayContent(children)
        }, duration)
        return () => {
            clearTimeout(timer)
        }
    }, [children])

    const styles = {
        display: 'inline-block',
        transition: `opacity ${duration}ms ease-out`,
        opacity: animation == Animation.OUT ? 0 : 1,
        ...style
    }

    const classes = cn(`${PREFIX}-emphasis`, className)

    switch (animation) {
        case Animation.IN:
            styles.animation = animations[animationIn] || animationIn
            break
        case Animation.OUT:
            styles.animation = animations[animationOut] || animationOut
            break
    }

    return <span style={styles} className={classes}>{displayContent}</span>
}

Emphasis.defaultProps = { duration: 200 }

Emphasis.displayName = 'Ts:Emphasis'
