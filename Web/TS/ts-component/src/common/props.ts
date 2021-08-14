
import * as React from 'react'
import {shadowClone} from "./utils";
import {SizeKind, TypeKind} from "./kinds";

/**
 * base props
 */
export interface IProps {
    className?: string
}

export interface IAppearanceProps {
    type?: TypeKind,
    size?: SizeKind
}

/**
 * clickable action props
 */
export interface IActionProps extends IProps {
    disabled?: boolean,
    iconName?: string,
    onClick?: (event: React.MouseEvent<HTMLElement>) => void,
    text?: React.ReactNode
}

export interface ILinkProps {
    href?: string,
    target?: string
}

const INVALID_PROPS = [
    'children',
    'iconName',
    'rightIconName',
    'leftIconName',
]

export function removeNonHTMLProps<T extends U, U>(props: T, invalidProps = INVALID_PROPS): U {
    return invalidProps.reduce((prev, props) => {
        if(prev.hasOwnProperty(props)) {
            delete prev[props]
        }
        return prev
    }, shadowClone(props))
}
