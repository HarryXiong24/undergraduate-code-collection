import React from "react";
import axios from "axios";

export default class List extends React.Component {

    constructor() {
        super();

        this.state = {
            name: "",
            url: ""
        }

    }
    
    // 在componentDidMount()里发送Ajax请求
    componentDidMount() {
        const url = "https://api.github.com/search/repositories?q=r&sort=stars";

        axios.get(url)
        .then( (response) => {
            console.log(response.data);
            const {name, url} = response.data.items[0];

            console.log({name, url});
            this.setState({name, url});
        })
        .catch( (error) => {
            console.log(error);
        })
    }
 
    render() {
        const {name, url} = this.state;
     
        if(!name){
            return (
                <h1>Loading...</h1>
            )
        }
        else{
            return (
            <h1>My Best like is <a href={url}>{name}</a> </h1>
            )
        }

    }
}