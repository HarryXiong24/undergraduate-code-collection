import React from 'react';

/**
 * 在react中，文本框里的值变化了，想要同步这种变化到state中去。
 * react没有这种机制，必须要使用onchange()事件进行手动监听
 * 并使用refs或者xxx.target.value，同时调用this.setState进行手动更新
 * 否则在react里面不会自动更新
 */


export default class TextOnchange extends React.Component {
    constructor() {
        super();
        this.state = {
            msg: "xhw"
        }
    }

    render() {
        return(
            <div>
                <input type="text" placeholder="Input you name" 
                onChange={
                    (msg) => {this.getInfo(msg)}
                } ref="text1"></input>
            </div>
        )
    }

    getInfo(msg) {
        // 法一(推荐)
        //console.log(this.refs.text1.value);
        //let str = this.refs.text1.value;

        // 法二
        console.log(msg.target.value);
        let str = msg.target.value;

        this.setState({
            msg: str
        })
    }
}

