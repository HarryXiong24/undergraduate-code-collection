import * as React from 'react'
import {Stack} from "../../components/stack/stack";
import {Card, CardSection} from "../../components/card/card";

import {Menu, MenuItem} from '../../../src';
import {MenuDivider} from "../../../src/components/menu/menuDivider";

export default class MenuDemo extends React.Component {
    public static readonly displayName = 'MenuDemo'

    public render() {
        return (
            <Card title="Menu 组件">
                <CardSection title="示例">
                    <Card>
                        <Stack>
                            <Menu className="menu-custom">
                                <MenuItem text="无序" />
                                <MenuItem text="有序" />
                                <MenuDivider title="组1" />
                                <MenuItem text="剪切" />
                                <MenuItem text="复制" />
                                <MenuItem text="黏贴" disabled={true} />
                                <MenuDivider title="组2" />
                                <MenuItem iconName="warn" text="对齐选项1">
                                    <MenuItem text="左对齐" />
                                    <MenuItem text="右对齐" />
                                    <MenuItem text="居中" />
                                    <MenuItem text="对齐选项2">
                                        <MenuItem text="左对齐" />
                                        <MenuItem text="右对齐" />
                                        <MenuItem text="居中" />
                                    </MenuItem>
                                </MenuItem>
                            </Menu>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
