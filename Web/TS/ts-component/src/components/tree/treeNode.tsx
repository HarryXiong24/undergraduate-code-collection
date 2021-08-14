import * as React from 'react'
import * as cn from 'classnames'
import {Collapse} from "../collapse/collapse";
import {safeInvoke} from "../../common/utils";
import {PREFIX} from "../../common/constants";

export type TreeNodeEventHandler = (node: TreeNode, event: React.MouseEvent<HTMLElement>) => void

export interface ITreeNode {
    childNodes?: ITreeNode[],
    className?: string,
    hasCaret?: boolean,
    id: string | number,
    isExpanded?: boolean,
    isSelected?: boolean,
    iconName?: string,
    label: string | JSX.Element,
    secondaryLabel?: string | JSX.Element
}

export interface ITreeNodeProps extends ITreeNode {
    children?: React.ReactNode,
    depth: number,
    key?: number | string,
    path: number[],
    onClick?: TreeNodeEventHandler,
    onDoubleClick?: TreeNodeEventHandler,
    onExpand?: TreeNodeEventHandler,
    onCollapse?: TreeNodeEventHandler,
}

export class TreeNode extends React.Component<ITreeNodeProps> {
    public static readonly displayName = 'Ts:TreeNode'

    public render() {
        const { isExpanded, isSelected, className, children, depth, label, iconName, secondaryLabel } = this.props
        const containerClass = cn(`${PREFIX}-tree-node`, {
            [`${PREFIX}-tree-node-expanded`]: isExpanded,
            [`${PREFIX}-tree-node-selected`]: isSelected
        }, className)
        const contentClass = cn(`${PREFIX}-tree-node-content`, `${PREFIX}-tree-node-content-${depth}`)
        const caretClass = cn(`${PREFIX}-tree-node-caret`, {
            [`${PREFIX}-tree-node-caret-opened`]: isExpanded,
            [`${PREFIX}-tree-node-caret-closed`]: !isExpanded
        })
        return (
            <li className={containerClass}>
                <div className={contentClass}
                     onClick={this.handleClick}
                     onDoubleClick={this.handleDoubleClick}
                >
                    <span className={caretClass} onClick={this.handleCaretClick}>
                        {isExpanded? '-' : '+'}
                    </span>
                    {this.maybeRenderIcon(iconName)}
                    <span className={`${PREFIX}-tree-node-label`}>{label}</span>
                    {this.maybeRenderSecondaryLabel(secondaryLabel)}
                </div>
                <Collapse isOpen={isExpanded}>
                    {children}
                </Collapse>
            </li>
        )
    }

    public handleClick = (event: React.MouseEvent<HTMLElement>) => {
        safeInvoke(this.props.onClick, this, event)
    }

    public handleDoubleClick = (event: React.MouseEvent<HTMLElement>) => {
        safeInvoke(this.props.onDoubleClick, this, event)
    }

    public handleCaretClick = (event: React.MouseEvent<HTMLElement>) => {
        event.stopPropagation()
        const { onCollapse, onExpand, isExpanded } = this.props
        safeInvoke(isExpanded ? onCollapse : onExpand, this, event)
    }


    public maybeRenderIcon(iconName?: string) {
        if(iconName != null) {
            return 'icon'
        }
        return null
    }

    public maybeRenderSecondaryLabel(secondaryLabel?: string | JSX.Element) {
        if(secondaryLabel != null) {
            return (
                <span className={`${PREFIX}-tree-node-secondary-label`}>
                    {secondaryLabel}
                </span>
            )
        }
        return null
    }
}
