import React from 'react';

// es6调用类的属性和实例方法都要加this关键字
export default class BtnEvent extends React.Component {
    constructor() {
        super();
        this.state = {
            msg: "oooo"
        };

        // 必须谨慎对待JSX回调函数中的this，
        // 在 JavaScript 中，class 的方法默认不会绑定 this。
        // 如果你忘记绑定 this.handleClick 并把它传入了 onClick，
        // 当你调用这个函数的时候 this 的值为 undefined。


        // 解决方法
        this.show = this.show.bind(this);

        // 或者定义成 show = () => {};
        
        // 或回调中使用箭头函数
        // () => {
        //     this.show();
        // } 但不推荐使用这种
    }

    show() {
        console.log("222");


        // 在react中，要修改this.state，不推荐使用this.state.xxx = ""
        // 推荐使用this.setState({传一个对象})
        this.setState({
            msg: "sda",
            ggs: "ss"
        });
    }


    // react为时间绑定函数推荐使用方法,先创建一个匿名箭头函数（因为它的this为包裹它的函数）
    // 之后再匿名箭头函数体内调用函数
    // react绑定事件不能使用普通js里的事件绑定方式
    render() {
        return(
            <div>
                <button onClick={
                    () => {
                        this.show();
                    }
                }>按钮</button>
            </div>
        )
    }

}