import * as React from 'react'
import {Card, CardSection} from "../../components/card/card";
import {Tree} from '../../../src';

export default class TreeDemo extends React.Component {
    public static readonly displayName = 'TreeDemo'

    public state = {
        contents: [
            {
                label: 'Node1',
                id: '11',
                childNodes: [
                    {
                        label: 'Node1-1',
                        id: '111'
                    },
                ]
            },
            {
                isExpanded: true,
                label: 'Node2',
                id: '22',
                childNodes: [
                    {
                        label: 'Node2-2',
                        id: '44',
                        childNodes: [
                            {
                                label: 'Node2-2-1',
                                id: '55',
                            },
                            {
                                label: 'Node2-2-2-1',
                                id: '66'
                            },
                        ],
                    },
                ],
            },
        ]
    }

    private handleNodeClick = () => {

    }

    private handleNodeCollapse = (nodeData) => {
        nodeData.isExpanded = false
        this.setState({
            contents: this.state.contents
        })
    }

    private handleNodeExpand = (nodeData) => {
        nodeData.isExpanded = true
        this.setState({
            contents: this.state.contents
        })
    }

    public render() {
        return (
            <Card title="选项树">
                <CardSection title="示例">
                    <Card>
                        <Tree
                            contents={this.state.contents}
                            onNodeClick={this.handleNodeClick}
                            onNodeCollapse={this.handleNodeCollapse}
                            onNodeExpand={this.handleNodeExpand}
                        />
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
