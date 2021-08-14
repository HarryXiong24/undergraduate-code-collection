import * as React from 'react'
import {Card, CardSection} from "../../components/card/card";
import {Dialog} from "../../../src";
import {Stack} from '../../components/stack/stack';

export default class DialogDemo extends React.Component {
    public static readonly displayName = 'DialogDemo'
    public state = {
        isOpen: false
    }
    private open = () => {
        this.setState({
            isOpen: !this.state.isOpen
        })
    }
    public render () {
        return (
            <Card title="对话框">
                <CardSection title="示例">
                    <Card>
                        <p style={{'cursor': 'pointer'}} onClick={this.open}>{this.state.isOpen ? 'CLOSE' : 'OPEN'}</p>
                    </Card>
                    <Dialog isOpen={this.state.isOpen} onClose={this.open} title={'温馨提示'} iconName="warn">
                        <Stack vertical={true}>
                            <p>IDE and Plugin Updates: IntelliJ IDEA is ready to update.</p>
                            <p>IDE and Plugin Updates: IntelliJ IDEA is ready to update.</p>
                            <p>IDE and Plugin Updates: IntelliJ IDEA is ready to update.</p>
                            <p>IDE and Plugin Updates: IntelliJ IDEA is ready to update.</p>
                        </Stack>
                    </Dialog>
                </CardSection>
            </Card>
        )
    }
}
