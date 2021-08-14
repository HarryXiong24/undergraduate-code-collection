import * as React from 'react'
import {Stack} from "../../components/stack/stack";
import {Card, CardSection} from "../../components/card/card";

import {Icon, SizeKind, TypeKind} from '../../../src';

export default class IconDemo extends React.Component {
    public static readonly displayName = 'IconDemo'

    public render() {
        return (
            <Card title="Icon 组件">
                <CardSection title="示例">
                    <Card>
                        <Stack>
                            <Icon name='check' size={SizeKind.SMALL}/>
                            <Icon name='close' size={SizeKind.SMALL}/>
                            <Icon name='warn' size={SizeKind.SMALL}/>
                            <Icon name='caret-left' size={SizeKind.SMALL}/>
                            <Icon name='caret-right' size={SizeKind.SMALL}/>
                            <Icon name='arrow-left' size={SizeKind.SMALL}/>
                            <Icon name='arrow-right' size={SizeKind.SMALL}/>
                        </Stack>
                        <Stack>
                            <Icon name='check'/>
                            <Icon name='close'/>
                            <Icon name='warn'/>
                            <Icon name='caret-left'/>
                            <Icon name='caret-right'/>
                            <Icon name='arrow-left'/>
                            <Icon name='arrow-right'/>
                        </Stack>
                        <Stack>
                            <Icon name='check' size={SizeKind.LARGE}/>
                            <Icon name='close' size={SizeKind.LARGE}/>
                            <Icon name='warn' size={SizeKind.LARGE}/>
                            <Icon name='caret-left' size={SizeKind.LARGE}/>
                            <Icon name='caret-right' size={SizeKind.LARGE}/>
                            <Icon name='arrow-left' size={SizeKind.LARGE}/>
                            <Icon name='arrow-right' size={SizeKind.LARGE}/>
                        </Stack>
                        <Stack>
                            <Icon name='check' size={SizeKind.LARGE} type={TypeKind.SUCCESS}/>
                            <Icon name='close' size={SizeKind.LARGE} type={TypeKind.INFO}/>
                            <Icon name='warn' size={SizeKind.LARGE} type={TypeKind.WARNING}/>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
