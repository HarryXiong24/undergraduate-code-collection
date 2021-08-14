import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {isUndefined} from "../../common/utils";

export interface IMenuDividerProps extends IProps {
    title?: string
}

export class MenuDivider extends React.Component<IMenuDividerProps> {
    public static displayName = 'Ts:MenuDivider'

    public render() {
        const {className, title} = this.props
        const dividerClasses = cn(`${PREFIX}-menu-divider`, className)
        const headerClasses = cn(`${PREFIX}-menu-header`, className)
        if(isUndefined(title)) {
            return <li className={dividerClasses}/>
        }
        return (
            <li className={headerClasses}>
                <h4 className={`${PREFIX}-menu-header-title`}>{title}</h4>
            </li>
        )
    }
}
