import * as React from 'react'
import * as ReactDom from 'react-dom'

import './index.scss'

import ButtonDemo from "./pages/button";
import CollapseDemo from "./pages/collapse";
import {Stack} from "./components/stack/stack";
import DialogDemo from "./pages/dialog";
import TreeDemo from "./pages/tree";
import SliderDemo from "./pages/slider";
import TabsDemo from "./pages/tabs";
import ControlDemo from "./pages/control";
import PopoverDemo from "./pages/popover";
import TooltipDemo from "./pages/tooltip";
import MenuDemo from "./pages/menu";
import ToasterDemo from "./pages/toaster";
import IconDemo from "./pages/icon";
import PaginationDemo from "./pages/pagination";
import DatePickerDemo from "./pages/datepicker";
import TableDemo from "./pages/table";

class Demo extends React.Component {
    public render() {
        return (
            <div className="demo">
                <Stack>
                    暂时只支持 PC 端！！
                </Stack>
                <Stack vertical={true}>
                    <ButtonDemo/>
                    <CollapseDemo/>
                    <DialogDemo/>
                    <TreeDemo/>
                    <SliderDemo/>
                    <TabsDemo/>
                    <ControlDemo/>
                    <PopoverDemo/>
                    <TooltipDemo/>
                    <MenuDemo/>
                    <ToasterDemo/>
                    <IconDemo/>
                    <PaginationDemo/>
                    <TableDemo/>
                </Stack>
            </div>
        )
    }
}

ReactDom.render(<Demo/>, document.getElementById('app'))
