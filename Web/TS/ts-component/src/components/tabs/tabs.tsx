import * as React from 'react'
import {findDOMNode} from 'react-dom'
import * as cn from 'classnames'
import {IProps} from "../../common/props";
import {PREFIX} from "../../common/constants";
import {ITabProps, Tab} from "./tab";
import {safeInvoke, uuid} from "../../common/utils";
import {ITabListProps} from "./tabList";
import {ENTER, SPACE} from "../../common/keys";

import './tabs.scss'

export interface ITabsProps extends IProps {
    animated?: boolean,
    selectedTabIndex?: number,
    onChange?: (value: number, lastSelectedTabIndex: number, tab: Tab) => void
}

export interface ITabsState {
    indicatorStyle?: React.CSSProperties
}

export class Tabs extends React.Component<ITabsProps, ITabsState> {
    public static readonly displayName = 'Ts:Tabs'

    public static defaultProps = {
        animated: true,
        selectedTabIndex: 0
    }

    public state = {
        indicatorStyle: null
    }

    public lastSelectedTabIndex: number

    private tabIds: string[] = []

    private panelIds: string[] = []

    constructor(props: ITabsProps, context?: any) {
        super(props, context)

        this.lastSelectedTabIndex = this.props.selectedTabIndex
    }

    public render() {
        const classes = cn(`${PREFIX}-tabs`, this.props.className)
        return (
            <div
                className={classes}
                onKeyDown={this.handleKeyDown}
            >
                {this.renderChild()}
            </div>
        )
    }

    private handleKeyDown = (event: React.KeyboardEvent) => {
        const target = (event.target as HTMLElement).closest(`.${PREFIX}-tab`) as HTMLElement
        if(target) {
            if(event.which == ENTER || event.which == SPACE) {
                const tab = this.getInstanceFromTarget(target)
                if(tab) {
                    tab.handleTabClick()
                }
            }
        }
    }

    private getInstanceFromTarget(target: HTMLElement) : Tab {
        return this[`tab${target.getAttribute('data-index')}`]
    }

    private getTabs(): React.ReactElement<ITabProps>[] {
        if(this.props.children == null) {
            return []
        }
        const tabs: React.ReactElement<ITabProps>[] = []
        if(React.Children.count(this.props.children)) {
            const firstChild = React.Children.toArray(this.props.children)[0] as React.ReactElement<{children?: React.ReactNode}>
            if(firstChild) {
                React.Children.map(firstChild.props.children, (child: React.ReactElement<any>) => {
                    if(child.type == Tab) {
                        tabs.push(child)
                    }
                })
            }
        }
        return tabs
    }

    private getTabsCount() {
        return this.getTabs().length
    }

    private renderChild() {
        for(let remain = this.getTabsCount() - this.tabIds.length; remain > 0; remain -= 1) {
            this.tabIds.push(`${PREFIX}-tab-${uuid()}`)
            this.panelIds.push(`${PREFIX}-tab-panel-${uuid()}`)
        }
        let index = 0
        return React.Children.map(this.props.children, (child: React.ReactElement<any>) => {
            if(index == 0) {
                index += 1
                return this.cloneTabList(child)
            } else {
                const panelIndex = index - 1
                const shouldRenderPanel = panelIndex == this.props.selectedTabIndex
                index += 1
                return shouldRenderPanel ? this.cloneTabPanel(child, panelIndex) : null
            }
        })
    }

    private cloneTabList(tabList: React.ReactElement<ITabListProps & {children?: React.ReactNode, ref?: (ref: React.ReactInstance) => void}>) {
        let index = 0
        const tabs = React.Children.map(tabList.props.children, (tab: React.ReactElement<ITabProps & {ref?: (ref: React.ReactInstance) => void}>) => {
            if(tab == null) {
                return null
            }
            let i = index
            const cloneTab = React.cloneElement(tab, {
                id: this.tabIds[i],
                index: i,
                panelId: this.panelIds[i],
                selected: this.props.selectedTabIndex == i,
                onTabClick: this.handleTabClick,
                ref: (ref) => {
                    this[`tab${i}`] = ref
                },
            })
            index += 1
            return cloneTab
        })
        return React.cloneElement(tabList, {
            children: tabs,
            animated: this.props.animated,
            indicatorStyle: this.state.indicatorStyle,
            ref: (ref) => this['tabList'] = ref
        })
    }

    private handleTabClick = (index: number, tab: Tab) => {
        safeInvoke(this.props.onChange, index, this.lastSelectedTabIndex, tab)
    }

    public componentWillReceiveProps(nextProps: ITabsProps) {
        if(this.props.selectedTabIndex != nextProps.selectedTabIndex) {
            this.lastSelectedTabIndex = this.props.selectedTabIndex
        }
    }

    public componentDidUpdate(prevProps: ITabsProps, _: ITabsState) {
        if(prevProps.selectedTabIndex != this.props.selectedTabIndex) {
            this.updateIndicatorStyle()
        }
    }

    public componentDidMount() {
        this.updateIndicatorStyle()
    }

    private updateIndicatorStyle() {
        const selectedTabElement = findDOMNode(this[`tab${this.props.selectedTabIndex}`]) as HTMLElement
        if(selectedTabElement) {
            const { clientHeight, clientWidth, offsetLeft, offsetTop} = selectedTabElement
            this.setState({
                indicatorStyle: {
                    height: clientHeight,
                    width: clientWidth,
                    transform: `translateX(${Math.floor(offsetLeft)}px) translateY(${Math.floor(offsetTop)}px)`,
                }
            })
        }
    }

    private cloneTabPanel(tabPanel: React.ReactElement<any>, tabIndex: number) {
        return React.cloneElement(tabPanel, {
            id: this.panelIds[tabIndex],
            tabId: this.tabIds[tabIndex],
            selected: this.props.selectedTabIndex == tabIndex,
            ref: (ref) => this[`tabPanel${tabIndex}`] = ref
        })
    }
}

1
