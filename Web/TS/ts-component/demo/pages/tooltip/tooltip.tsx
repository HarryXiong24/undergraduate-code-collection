import * as React from 'react'
import {Stack} from "../../components/stack/stack";
import {Card, CardSection} from "../../components/card/card";

import {PositionKind, Tooltip} from '../../../src';
import {TypeKind} from "../../../src";

export default class PopoverDemo extends React.Component {
    public static readonly displayName = 'TooltipDemo'

    public render() {
        return (
            <Card title="Tooltip 组件">
                <CardSection title="theme">
                    <Card>
                        <Stack>
                            <Tooltip position={PositionKind.TOP} type={TypeKind.DEFAULT}>
                                <span>Default</span>
                                <div>TypeKind.DEFAULT</div>
                            </Tooltip>
                            <Tooltip position={PositionKind.TOP} type={TypeKind.SUCCESS}>
                                <span>Success</span>
                                <div>TypeKind.SUCCESS</div>
                            </Tooltip>
                            <Tooltip position={PositionKind.TOP} type={TypeKind.INFO}>
                                <span>Info</span>
                                <div>TypeKind.INFO</div>
                            </Tooltip>
                            <Tooltip position={PositionKind.TOP} type={TypeKind.WARNING}>
                                <span>Warning</span>
                                <div>TypeKind.WARNING</div>
                            </Tooltip>
                            <Tooltip position={PositionKind.TOP} type={TypeKind.DANGER}>
                                <span>Danger</span>
                                <div>TypeKind.DANGER</div>
                            </Tooltip>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
