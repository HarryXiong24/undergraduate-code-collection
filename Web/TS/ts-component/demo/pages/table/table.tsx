import * as React from 'react'
import {Card, CardSection} from "../../components/card/card";
import {Table, TTableProps} from "../../../src";
import {Stack} from '../../components/stack/stack';

export default class DatePickerDemo extends React.Component {
    public static readonly displayName = 'DatePickerDemo'

    public state: TTableProps = {
        data: [
            {
                name: '测试1测试1测试1测试1测试1测试1测试1测试1测试1测试1', nick: 'test1', gender: '男生', key: '1'
            },
            {
                name: '测试2', nick: 'test2', gender: '男生', key: '2'
            },
            {
                name: '测试3', nick: 'test3', gender: '女生', key: '3'
            }
        ],
        columns: [
            {
                title: '名称', field: 'name', width: 150, fixed: 'left'
            },
            {
                title: '昵称', field: 'nick', width: 150
            },
            {
                title: '性别', field: 'gender', width: 150
            },
            {
                title: '名称', field: 'name', width: 150
            },
            {
                title: '昵称', field: 'nick', width: 150
            },
            {
                title: '性别', field: 'gender', width: 150
            },
            {
                title: '名称', field: 'name', width: 150
            },
            {
                title: '昵称', field: 'nick', width: 150
            },
            {
                title: '性别', field: 'gender', width: 150
            }
        ],

    }

    public onDayClick = () => {
        this.setState({})
    }

    public render() {
        return (
            <Card title="Table 组件">
                <CardSection title="示例">
                    <Card>
                        <Stack>
                            <Table columns={this.state.columns} data={this.state.data}/>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
