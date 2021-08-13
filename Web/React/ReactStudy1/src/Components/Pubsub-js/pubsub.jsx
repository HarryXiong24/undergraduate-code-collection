import React from "react";
import Pubsub from "pubsub-js";


export default class App extends React.Component {
    
    constructor() {
        super();
        this.state = {
            data: ""
        }
    }

    componentDidMount() {
        Pubsub.subscribe('mySet', (msg, data) => {
            let newState = {data};
            this.setState(newState);
        })
    }

    render() {
        return (
            <div>
                <Part></Part>
                <p>{this.state.data}</p>
            </div>
        )
    }

}

class Part extends React.Component {
    
    set = () => {
        let value = this.refs.input.value;
        Pubsub.publish('mySet', value);
    }


    render() {
        return (
            <div>
                <input type="text" ref="input"></input>
                <button onClick={this.set}>Submit</button>
            </div>
        )
    }
} 