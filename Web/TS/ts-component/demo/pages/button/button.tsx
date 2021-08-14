import * as React from 'react'
import {Stack} from "../../components/stack/stack";
import {Card, CardSection} from "../../components/card/card";

import {Button, SizeKind, TypeKind} from '../../../src';

export default class ButtonDemo extends React.Component {
    public static readonly displayName = 'ButtonDemo'

    public render() {
        return (
            <Card title="按钮组件">
                <CardSection title="按钮类型">
                    <Card>
                        <Stack>
                            <Button>DEFAULT</Button>
                            <Button rightIconName="arrow-right" type={TypeKind.PRIMARY}>PRIMARY</Button>
                            <Button type={TypeKind.DANGER}>DANGER</Button>
                        </Stack>
                    </Card>
                </CardSection>
                <CardSection title="按钮尺寸">
                    <Card>
                        <Stack>
                            <Button size={SizeKind.SMALL}>SMALL</Button>
                            <Button rightIconName="arrow-right" type={TypeKind.PRIMARY}>PRIMARY</Button>
                            <Button type={TypeKind.DANGER} size={SizeKind.LARGE}>LARGE</Button>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
