import * as React from 'react'
import {Stack} from "../../components/stack/stack";
import {Card, CardSection} from "../../components/card/card";

import {Popover, PositionKind, PopperInteractionKind} from '../../../src';

export default class PopoverDemo extends React.Component {
    public static readonly displayName = 'PopoverDemo'

    public render() {
        return (
            <Card title="Popover 组件">
                <CardSection title="Position">
                    <Card>
                        <Stack>
                            <Popover position={PositionKind.LEFT} interactionKind={PopperInteractionKind.HOVER_TARGET}>
                                <span>LEFT</span>
                                <div>Position.LEFT</div>
                            </Popover>
                            <Popover position={PositionKind.RIGHT} interactionKind={PopperInteractionKind.HOVER_TARGET}>
                                <span>RIGHT</span>
                                <div>Position.RIGHT</div>
                            </Popover>
                            <Popover position={PositionKind.TOP} interactionKind={PopperInteractionKind.HOVER_TARGET}>
                                <span>TOP</span>
                                <div>Position.TOP</div>
                            </Popover>
                            <Popover position={PositionKind.BOTTOM} interactionKind={PopperInteractionKind.HOVER_TARGET}>
                                <span>BOTTOM</span>
                                <div>Position.BOTTOM</div>
                            </Popover>
                            <Popover position={PositionKind.BOTTOM_LEFT} interactionKind={PopperInteractionKind.HOVER}>
                                <span>BOTTOM_LEFT</span>
                                <div>Position.BOTTOM_LEFT</div>
                            </Popover>
                            <Popover position={PositionKind.TOP_LEFT} interactionKind={PopperInteractionKind.CLICK}>
                                <span>CLICK</span>
                                <div>Position.TOP_LEFT</div>
                            </Popover>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
