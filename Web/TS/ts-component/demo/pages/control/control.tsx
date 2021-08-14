import * as React from 'react'
import {Stack} from "../../components/stack/stack";
import {Card, CardSection} from "../../components/card/card";
import {Checkbox, Radio, RadioGroup, CheckboxGroup} from '../../../src';

export default class ControlDemo extends React.Component {
    public static readonly displayName = 'ButtonDemo'

    public state = {
        checkbox1: false,
        radio1: false,
        switch1: false,
        radioGroup: 'radio-0',
        checkboxGroup: ['checkbox-0', 'checkbox-1']
    }

    public handleChange = (field, val) => {
        this.setState({
            [field]: val
        })
    }

    public render() {
        return (
            <Card title="Control 组件">
                <CardSection title="Checkbox">
                    <Card>
                        <Stack>
                            <Checkbox onChange={(checked) => this.handleChange('checkbox1', checked)}
                                      checked={this.state.checkbox1} label={'复选框'}/>
                        </Stack>
                    </Card>
                </CardSection>
                <CardSection title="Radio">
                    <Card>
                        <Stack>
                            <Radio onChange={(checked) => this.handleChange('radio1', checked)}
                                   checked={this.state.radio1} label={'单选框'}/>
                        </Stack>
                    </Card>
                </CardSection>
                <CardSection title="RadioGroup">
                    <Card>
                        <Stack>
                            <RadioGroup onChange={(checked, val) => this.handleChange('radioGroup', val)}
                                        selectedValue={this.state.radioGroup} name="radioGroup" label={'组合框'}>
                                <Radio value="radio-0">radio-0</Radio>
                                <Radio value="radio-1" disabled={true}>radio-0</Radio>
                                <Radio value="radio-2">radio-0</Radio>
                            </RadioGroup>
                        </Stack>
                    </Card>
                </CardSection>
                <CardSection title="CheckboxGroup">
                    <Card>
                        <Stack>
                            <CheckboxGroup onChange={(checked, val) => this.handleChange('checkboxGroup', val)}
                                           selectedValue={this.state.checkboxGroup} name="checkboxGroup" label={'组合框'}>
                                <Checkbox value="checkbox-0">radio-0</Checkbox>
                                <Checkbox value="checkbox-1" disabled={true}>radio-0</Checkbox>
                                <Checkbox value="checkbox-2">radio-0</Checkbox>
                            </CheckboxGroup>
                        </Stack>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
