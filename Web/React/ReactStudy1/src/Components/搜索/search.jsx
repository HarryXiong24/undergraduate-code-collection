import React from "react";

export default class Search extends React.Component {

    readMsg = () => {
        let content = this.refs.input.value;
        this.props.setMsg(content);
    }

    render() {
        return (
            <section className="jumbotron">
                <h3 className="jumbotron-heading">Search Github Users</h3>
                <div>
                    <input type="text" placeholder="Enter the name you search" ref="input"/>
                    <button onClick={this.readMsg}>Search</button>
                </div>
            </section>
               
        )
    }

}
