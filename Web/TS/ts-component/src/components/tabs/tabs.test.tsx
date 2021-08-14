import {mount, ReactWrapper} from "enzyme";
import {TabList} from "./tabList";
import {Tab} from "./tab";
import {TabPanel} from "./tabPanel";
import {Tabs} from "./tabs";
import * as React from "react";
import {PREFIX} from "../../common/constants";
import * as keys from "../../common/keys";

describe('Tabs', () => {
    let wrapper: ReactWrapper<{}, {}>
    let container: HTMLElement

    beforeEach(() => {
        container = document.createElement('div')
        document.body.appendChild(container)
    })
    afterEach(() => {
        container.remove()
    })

    it('calc children counts', () => {
        wrapper = mount((
            <Tabs>
                {getTabsContents()}
            </Tabs>
        ))
        expect(wrapper.find(Tab)).toHaveLength(3)
        expect(wrapper.find(TabPanel)).toHaveLength(1)
    })

    it('change tab focus when keyboard was pressed', () => {
        wrapper = mount((
            <Tabs>
                {getTabsContents()}
            </Tabs>
        ), {attachTo: container})

        const tab2 = wrapper.find(`.${PREFIX}-tab`).last()
        wrapper.simulate('keyDown', {which: keys.TAB, keyCode: keys.TAB})
        wrapper.simulate('keyDown', {which: keys.ENTER, keyCode: keys.ENTER})
        expect(tab2.hasClass(`.${PREFIX}-tab-selected`)).toBeTruthy()
    })

    function getTabsContents(): Array<React.ReactElement<any>> {
        return [
            <TabList key={0}>
                <Tab key={1}>
                    JavaScript
                </Tab>
                <Tab key={2} disabled={true}>
                    TypeScript
                </Tab>
                <Tab key={3}>
                    GoLang
                </Tab>
            </TabList>,
            <TabPanel key={4}>
                JavaScript。<br/>
            </TabPanel>,
            <TabPanel key={5}>
                TypeScript。<br/>
            </TabPanel>,
            <TabPanel key={6}>
                GoLang。<br/>
            </TabPanel>
        ];
    }
})
