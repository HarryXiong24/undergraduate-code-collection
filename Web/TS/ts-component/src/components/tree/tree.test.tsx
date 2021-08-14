import * as React from 'react'
import {Tree} from "./tree";
import {mount} from "enzyme";
import {PREFIX} from "../../common/constants";

describe('Testing Tree component', () => {
    let wrapper

    it(`wrapper contents in a div with .${PREFIX}-tree class`, () => {
        wrapper = renderTree()
        expect(wrapper.find(`.${PREFIX}-tree`).length).toEqual(1)
    })
    const createContents = () => {
        return [
            {
                label: 'Node1',
                id: '11',
                childNodes: [
                    {
                        label: 'Node1-1',
                        id: '111'
                    },
                ]
            },
            {
                isExpanded: true,
                label: 'Node2',
                id: '22',
                childNodes: [
                    {
                        label: 'Node2-1',
                        id: '33'
                    },
                    {
                        label: 'Node2-2',
                        id: '44',
                        childNodes: [
                            {
                                label: 'Node2-2-1',
                                id: '55',
                            },
                            {
                                label: 'Node2-2-2-1',
                                id: '66'
                            },
                            {
                                label: 'Node2-2-2-2',
                                id: '77'
                            },
                        ],
                    },
                ],
            },
        ]
    }

    const renderTree = (props?: object) => {
        return mount(<Tree contents={createContents()} {...props}/>)
    }
})
