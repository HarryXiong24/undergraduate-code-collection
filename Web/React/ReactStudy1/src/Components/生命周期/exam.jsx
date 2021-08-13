import React from "react";
import ReactDom from "react-dom";

export default class Life extends React.Component {

    constructor() {
        super();
        this.state = {
            value: 1
        }
    }

    componentDidMount() {
        this.timer = setInterval( () => {
            let newState = this.state;
            newState.value += 1;
            if(newState.opacity > 100){
                newState.opacity = 1;
            }

            this.setState(newState);

        }, 500)
    }

    componentWillUnmount() {
        clearInterval(this.timer);
    }

    destroy = () =>{
        ReactDom.unmountComponentAtNode(document.getElementById("root"));
    }

    render() {
        return (
            <div id="box">
                <h2>{this.state.value}</h2>
                <button onClick={
                    this.destroy
                }>Close</button>
            </div>
        )
    }
}
