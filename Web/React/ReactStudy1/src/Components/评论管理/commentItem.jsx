import React from "react";
import cssAPP from "./exam.module.css";


export default class Item extends React.Component {

    addToList = () => {
        let name = this.refs.name.value;
        let content = this.refs.content.value;
        let newMsg = {name, content};
        this.props.addMsg(newMsg);

        this.refs.name.value = "";
        this.refs.content.value = "";
    }

    render() {
        return (
            <div id={cssAPP.item}>

                <div className={cssAPP.name}>
                    <p>用户名</p>
                    <input type="text" placeholder="Please Input name" ref="name"></input>
                </div>

                <div className={cssAPP.content}>
                    <p>评论内容</p> 
                    <textarea placeholder="Please Input your content" ref="content"></textarea>      
                </div>

                <button onClick={
                    () => {this.addToList()}
                }>Submit</button>

            </div>
        )
    }
}