import React from "react";
import Search from "./search";
import Show from "./show";

export default class App extends React.Component {
    constructor(){
        super();
        this.state = {
            searchMsg: ""
        }
    }

    setMsg = (msg) => {
        const newState = {
            searchMsg: msg
        }

        this.setState(newState);
    }

    render() {
        return (
            <div className="container">
                <Search setMsg={this.setMsg}></Search>
                <Show searchMsg={this.state.searchMsg}></Show>
            </div>
        )
    }

}
