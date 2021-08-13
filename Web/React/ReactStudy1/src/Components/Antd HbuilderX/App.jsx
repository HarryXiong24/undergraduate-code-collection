import React from "react";
import Nav from "./Nav";
import Carousels from "./Carousels";
import WeDo from "./WeDo";
import Content from "./Content";
import TheySay from "./TheySay.jsx";
import Footer from "./Footer"

export default class App extends React.Component {
    render() {
        return (
            <div>
                <Nav></Nav>
                <Carousels></Carousels>
                <WeDo></WeDo>
                <Content></Content>
                <TheySay></TheySay>
                <Footer></Footer>
            </div>
        )
    }
}
