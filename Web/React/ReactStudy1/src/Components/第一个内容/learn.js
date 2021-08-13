import React from 'react';
import ReactDOM from 'react-dom';

// 简单的写法
// let h1 = <h1>xhw</h1>;
// ReactDOM.render(h1, document.getElementById("root"));

console.log("ok");

// 创建组件的原理
// const createApp = (props) => {
//     // 一个return只能返回一个html块
//     return (
//         <div>
//             {
//                 /* js代码用花括号就可以表示 */
//             }
//             <p>Welcome {props.title}</p>
//         </div>
//     )
// }
// const app = createApp({
//     title: "XHW"
// })

// 创建组件的第一种方式
// props传入的是属性
const App = (props) => {
    // 一个return只能返回一个html块
    return (
        <div id="box">
            {
                /* js代码用花括号就可以表示 */
            }
            <p>Welcome {props.title}</p>
        </div>
    )
}
ReactDOM.render(<App title="XHW"><p>xhw</p></App>, document.getElementById("root"));


// 第二种创建组件的方式（类组件）
class App2 extends React.Component {
    constructor(){
        super();
        // 可读可写
        this.state = {
            msg: "12456"
        };
    }

    render() {
        // this.props只能读不能写
        return (
            <div>
                <p>{this.props.title}</p>  
            </div>
        );
    }
}
ReactDOM.render(<App2 title="XHW"><p>xhw</p></App2>, document.getElementById("box"));
