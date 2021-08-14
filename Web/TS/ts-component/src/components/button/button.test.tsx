import * as React from 'react'
import { shallow, mount } from 'enzyme'
import {Button} from "./button";

describe('Testing Button component', () => {
    let wrapper
    let onClick
    it('test contents', () => {
        wrapper = shallow(<Button className="button">
            测试按钮
        </Button>)
        expect(wrapper.is('button')).toBeTruthy()
        expect(wrapper.hasClass('button')).toBeTruthy()
        expect(wrapper.contains('测试按钮')).toBeTruthy()
    })

    it('click works well when disabled is false', () => {
        onClick = jest.fn();
        wrapper = shallow(<Button className="button" onClick={onClick}>
            测试按钮
        </Button>)
        wrapper.simulate('click')
        expect(onClick).toBeCalled()
    })

    it('can\'t be clicked when disabled is true', () => {
        onClick = jest.fn();
        wrapper = mount(<Button disabled={true} className="button" onClick={onClick}>
            测试按钮
        </Button>)
        wrapper.simulate('click')
        expect(onClick.mock.calls.length).toBeLessThan(1)
    })
})
