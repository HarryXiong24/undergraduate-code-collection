import * as cn from 'classnames'
import * as React from 'react'
import {IconModel, icons} from './icons'
import {IAppearanceProps, IProps, IActionProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {SizeKind} from "../../common/kinds";
import {isUndefined, safeInvoke} from "../../common/utils";

import './icon.scss'

export interface IIconProps extends IProps, IAppearanceProps, IActionProps {
    name?: string,
    tagName?: keyof JSX.IntrinsicElements,
    title?: string,
    width?: number | string,
    height?: number | string,
    fill?: string
}

export class Icon extends React.Component<IIconProps> {
    public static displayName = 'Ts:Icon'

    public static defaultProps = {
        fill: 'currentColor',
        tagName: 'span',
        width: 16,
        height: 16,
    }

    public render() {
        const {tagName: TagName, name, title, className, fill, type, disabled, ...rest} = this.props
        const {width, height} = this.getIconBounds()
        const iconClasses = cn(`${PREFIX}-icon`, `${PREFIX}-icon-${name}`, {
            [`${PREFIX}-icon-${type}`]: type,
            [`${PREFIX}-icon-disabled`]: disabled,
        }, className)
        const path = icons[name] as IconModel
        return (
            // @ts-ignore
            <TagName {...rest} onClick={this.handleClick} className={iconClasses}>
                <svg fill={fill}
                     width={width}
                     height={height}
                     data-id={`${PREFIX}-${name}`}
                     viewBox={path.viewBox}>
                    <title>{title ? title : path.title}</title>
                    <path d={path.d}/>
                </svg>
            </TagName>
        )
    }

    private handleClick = (event: React.MouseEvent<HTMLElement>) => {
        safeInvoke(this.props.onClick, event)
    }

    private getIconBounds() {
        let {width, height, size} = this.props
        if (!isUndefined(size)) {
            switch (size) {
                case SizeKind.SMALL:
                    width = height = 14
                    break
                case SizeKind.LARGE:
                    width = height = 18
                    break
            }
        }

        return {width, height}
    }
}


