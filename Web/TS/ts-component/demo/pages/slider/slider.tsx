import * as React from 'react'
import {Card, CardSection} from "../../components/card/card";
import {Slider} from '../../../src';

export default class SliderDemo extends React.Component {
    public static readonly displayName = 'SliderDemo'
    public state = {
        value: 5
    }
    public handleSliderChange = (value) => {
        this.setState({value})
    }
    public render () {
        return (
            <Card title="滑动块">
                <CardSection title="示例">
                    <Card>
                        <Slider
                            onChange={this.handleSliderChange}
                            min={0}
                            max={100}
                            stepSize={1}
                            labelStepSize={10}
                            value={this.state.value}/>
                    </Card>
                </CardSection>
            </Card>
        )
    }
}
