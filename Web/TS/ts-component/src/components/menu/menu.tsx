import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";

import './menu.scss'

export class Menu extends React.Component<IProps> {
    public static displayName = 'Ts:Menu'

    public render() {
        const {className, children} = this.props
        const menuClasses = cn(`${PREFIX}-menu`, className)
        return (
            <ul className={menuClasses}>
                {children}
            </ul>
        )
    }
}
