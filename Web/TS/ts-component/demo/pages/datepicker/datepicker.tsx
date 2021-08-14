import * as React from 'react'
import {Card, CardSection} from "../../components/card/card";
import {DatePicker, IDatePickerProps} from "../../../src";
import {Stack} from '../../components/stack/stack';

export default class DatePickerDemo extends React.Component {
    public static readonly displayName = 'DatePickerDemo'

    public state: IDatePickerProps = {
        month: new Date(),
        selectedDays: new Date('2019-03-14'),
        disabledDays: new Date('2019-03-25')
    }

    public onDayClick = (day: Date) => {
        this.setState({
            selectedDays: day
        })
    }

    public render() {
        return (
            <Card title="DatePicker 组件">
                <CardSection title="示例">
                    <Card>
                        <Stack>
                            <DatePicker {...this.state} onDayClick={this.onDayClick}/>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
