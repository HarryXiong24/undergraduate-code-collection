import React from "react";
import css from "./exam.module.css";

export default class App extends React.Component {
    constructor() {
        super();
        // 是个对象
        this.state = {
            todo: ["aa", "bb"]
        };

        this.addTodo = this.addTodo.bind(this);
    }
    
    addTodo(todo) {
        const newState = this.state;
        // unshift()将新的值放到最前的位置里
        newState.todo.unshift(todo);
        // 要重新传一个对象
        this.setState(newState);
    }

    render() {
        return (
            <div id={css.wrap}>
                <p>TODO List</p>
                <Add addTodo={this.addTodo}></Add>
                <List todo={this.state.todo}></List>
            </div>
        )
    }
}

class Add extends React.Component {

    constructor() {
        super();
        this.state = {};
        this.add = this.add.bind(this);
    }
    
    add(){
        let str = this.refs.textInput.value;
        this.props.addTodo(str);
        this.refs.textInput.value = "";
    }

    render() {
        return (
            <div id={css.add}>
               <input type="text" placeholder="Input content" ref="textInput" ></input>
               <button onClick={
                   () => {
                        this.add();
                   }
               }>Submit</button>
            </div>
        )
    }
}

class List extends React.Component {

    render() {
        return (
            <div id={css.list}>
                <ul>
                    {
                        this.props.todo.map(
                            (todo, index) => {
                                return <li key={index}>{todo}</li>;
                            }
                        )
                    }
                </ul>
            </div>
        )
    }
}