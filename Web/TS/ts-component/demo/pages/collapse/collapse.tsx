import * as React from 'react'
import {Card, CardSection} from "../../components/card/card";
import {Collapse} from "../../../src";
import {Stack} from '../../components/stack/stack';

export default class CollapseDemo extends React.Component {
    public static readonly displayName = 'CollapseDemo'
    public state = {
        isOpen: true
    }
    private open = () => {
        this.setState({
            isOpen: !this.state.isOpen
        })
    }
    public render () {
        return (
            <Card title="折叠组件">
                <CardSection title="示例">
                    <Card>
                        <p style={{'cursor': 'pointer'}} onClick={this.open}>{this.state.isOpen ? 'COLLAPSE' : 'EXPAND'}</p>
                        <Collapse isOpen={this.state.isOpen}>
                            <Stack vertical={true}>
                                <p>IDE and Plugin Updates: IntelliJ IDEA is ready to update.</p>
                                <p>IDE and Plugin Updates: IntelliJ IDEA is ready to update.</p>
                                <p>IDE and Plugin Updates: IntelliJ IDEA is ready to update.</p>
                                <p>IDE and Plugin Updates: IntelliJ IDEA is ready to update.</p>
                            </Stack>
                        </Collapse>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
