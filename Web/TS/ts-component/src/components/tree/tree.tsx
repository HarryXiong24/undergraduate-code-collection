import * as React from 'react'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {ITreeNode, TreeNode} from "./treeNode";
import {isFunction} from "../../common/utils";
import {PREFIX} from "../../common/constants";

import './tree.scss'

export type TreeEventHandler = (node: ITreeNode, nodePath: number[], event: React.MouseEvent<HTMLElement>) => void

export interface ITreeProps extends IProps {
    contents: ITreeNode[],
    onNodeClick?: TreeEventHandler,
    onNodeDoubleClick?: TreeEventHandler,
    onNodeCollapse?: TreeEventHandler,
    onNodeExpand?: TreeEventHandler
}

export class Tree extends React.Component<ITreeProps> {
    public static readonly displayName = 'Ts:Tree'

    private static nodeFromPath(path: number[], treeNodes: ITreeNode[]): ITreeNode {
        if(path.length == 1) {
            return treeNodes[path[0]]
        } else {
            return Tree.nodeFromPath(path.slice(1), treeNodes[path[0]].childNodes)
        }
    }

    public render() {
        const classes = cn(`${PREFIX}-tree`, this.props.className)
        return (
            <div className={classes}>
                {this.renderNodes(this.props.contents, [], 'ts-tree-root')}
            </div>
        )
    }

    public renderNodes(treeNodes: ITreeNode[], currentPath: number[], className?: string): JSX.Element {
        if(treeNodes == null) {
            return null
        }
        const nodeItems = treeNodes.map((node, i) => {
            const nodePath = currentPath.concat(i)
            return (
                <TreeNode
                    {...node}
                    key={node.id}
                    depth={nodePath.length - 1}
                    onClick={this.onNodeClick}
                    onDoubleClick={this.onNodeDoubleClick}
                    onCollapse={this.onNodeCollapse}
                    onExpand={this.onNodeExpand}
                    path={nodePath}
                >
                    {this.renderNodes(node.childNodes, nodePath)}
                </TreeNode>
            )
        })
        return (
            <ul className={cn(`${PREFIX}-tree-list`, className)}>
                {nodeItems}
            </ul>
        )
    }

    private onNodeClick = (node: TreeNode, event: React.MouseEvent<HTMLElement>) => {
        this.handlerHelper(this.props.onNodeClick, node, event)
    }

    private onNodeDoubleClick = (node: TreeNode, event: React.MouseEvent<HTMLElement>) => {
        this.handlerHelper(this.props.onNodeDoubleClick, node, event)
    }

    private onNodeCollapse = (node: TreeNode, event: React.MouseEvent<HTMLElement>) => {
        this.handlerHelper(this.props.onNodeCollapse, node, event)
    }

    private onNodeExpand = (node: TreeNode, event: React.MouseEvent<HTMLElement>) => {
        this.handlerHelper(this.props.onNodeExpand, node, event)
    }

    private handlerHelper(handlerFunc: TreeEventHandler, node: TreeNode, event: React.MouseEvent<HTMLElement>) {
        if(isFunction(handlerFunc)) {
            const nodeData = Tree.nodeFromPath(node.props.path, this.props.contents)
            handlerFunc(nodeData, node.props.path, event)
        }
    }
}
