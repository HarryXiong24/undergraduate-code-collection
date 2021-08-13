import React from "react";
import cssAPP from "./exam.module.css";


export default class Item extends React.Component {

    delete = (event) => {
        let index = event.target.key;

        // confirm必须要在widow下使用
        let tip = window.confirm(`确定删除${event.target.name}的评论吗?`);

        if(tip){
            this.props.deleteMsg(index);
        }
       
    }

    render() {
        console.log(this.props.msg);
        return (
            <div id={cssAPP.list}>
                <h2>评论回复</h2>
                {
                    this.props.msg.map( 
                        (items, index) => 
                        
                        <div key={index} name={items.name}>
                            <h3>{items.name}</h3>
                            <p>{items.content}</p>
                            <button onClick={
                                (event) => {this.delete(event)}
                            } name={items.name} key={index}>Delete</button>
                        </div>
                    )
                }

            </div>
        )
    }
}