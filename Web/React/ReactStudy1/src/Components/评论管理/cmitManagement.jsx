import React from "react";
import cssAPP from "./exam.module.css";
import Item from "./commentItem";
import List from "./commentLists";


export default class App extends React.Component {
    constructor() {
        super();
        this.state = {
            msg: [
                    {name: "XHW", content: "I am iron man."},
                    ]
        }
    }

    addMsg = (inputMsg) => {
        const temp = this.state;
        temp.msg.unshift(inputMsg);
        this.setState(temp);
    }

    deleteMsg = (index) => {
        const temp = this.state;
        temp.msg.splice(index, 1);
        this.setState(temp);
    }

    render() {
        return (
            <div id={cssAPP.wrap}>
                <div className={cssAPP.head}>
                    <p>请发表对React的评论</p>
                </div>
                <Item addMsg={this.addMsg}></Item>
                <List msg={this.state.msg} deleteMsg={this.deleteMsg}></List>
            </div>
        )
    }
}