import * as React from 'react'
import {Stack} from "../../components/stack/stack";
import {Card, CardSection} from "../../components/card/card";

import {Button, PositionKind, Toaster, TypeKind} from '../../../src';

export default class ToasterDemo extends React.Component {
    public static readonly displayName = 'ToasterDemo'

    public state = {
        position: PositionKind.TOP
    }

    public id: number = 0

    public toaster: Toaster

    public refHandlers = {
        toaster: (ref: Toaster) => {
            this.toaster = ref
        }
    }

    public addToaster(position) {
        this.setState({
            position: position
        }, () => {
            this.id++
            this.toaster.show({
                message: `Toaster 消息: ${this.id}`,
                showDismissButton: true,
                type: TypeKind.SUCCESS,
            })
        })
    }

    public render() {
        return (
            <Card title="Toaster 组件">
                <CardSection title="示例">
                    <Card>
                        <Stack>
                            <Toaster ref={this.refHandlers.toaster} position={this.state.position} />
                        </Stack>
                        <Stack>
                            <Button type={TypeKind.PRIMARY} onClick={this.addToaster.bind(this, PositionKind.TOP)}>
                                Default
                            </Button>
                            <Button type={TypeKind.PRIMARY} onClick={this.addToaster.bind(this, PositionKind.TOP_RIGHT)}>
                                TOP_RIGHT
                            </Button>
                            <Button type={TypeKind.PRIMARY} onClick={this.addToaster.bind(this, PositionKind.TOP_LEFT)}>
                                TOP_LEFT
                            </Button>
                            <Button type={TypeKind.PRIMARY} onClick={this.addToaster.bind(this, PositionKind.BOTTOM_LEFT)}>
                                BOTTOM_LEFT
                            </Button>
                            <Button type={TypeKind.PRIMARY} onClick={this.addToaster.bind(this, PositionKind.BOTTOM_RIGHT)}>
                                BOTTOM_RIGHT
                            </Button>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
