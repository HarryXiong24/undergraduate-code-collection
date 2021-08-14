import * as React from 'react'
import {Card, CardSection} from "../../components/card/card";
import {Tab, TabList, TabPanel, Tabs} from '../../../src';

export default class TabsDemo extends React.Component {
    public static readonly displayName = 'TabsDemo'
    public state = {
        selectedTabIndex: 0
    }
    public handleTabsChange = (selectedTabIndex) => {
        this.setState({selectedTabIndex})
    }
    public render () {
        return (
            <Card title="滑动块">
                <CardSection title="示例">
                    <Card>
                        <Tabs selectedTabIndex={this.state.selectedTabIndex} onChange={this.handleTabsChange}>
                            <TabList>
                                <Tab>
                                    JavaScript
                                </Tab>
                                <Tab>
                                    TypeScript
                                </Tab>
                                <Tab disabled={true}>
                                    GoLang
                                </Tab>
                            </TabList>
                            <TabPanel>
                                JavaScript，通常缩写为JS，是一种高级的，解释执行的编程语言。<br/>
                                JavaScript是一门基于原型、函数先行的语言，是一门多范式的语言，它支持面向对象编程，命令式编程，以及函数式编程。<br/>
                                它提供语法来操控文本、数组、日期以及正则表达式等，不支持I/O，比如网络、存储和图形等，但这些都可以由它的宿主环境提供支持。<br/>
                            </TabPanel>
                            <TabPanel>
                                TypeScript是一种由微软开发的自由和开源的编程语言。<br/>
                                TypeScript带来了可选的静态类型检查以及最新的ECMAScript特性。<br/>
                            </TabPanel>
                            <TabPanel>
                                GoLang。<br/>
                            </TabPanel>
                        </Tabs>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
