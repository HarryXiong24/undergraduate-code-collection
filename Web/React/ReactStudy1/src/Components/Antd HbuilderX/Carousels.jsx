/* eslint-disable no-script-url */
/* eslint-disable jsx-a11y/anchor-is-valid */
import React from "react";
import { Carousel } from 'antd';
import { Button } from 'antd';
import dnImg from "./img/dn.png";

export default class Carousels extends React.Component {

  constructor() {
    super();
    this.state = {
      display: "none"
    }

  }

  Prev = () => {
    this.refs.ca.prev();
  }

  Next = () => {
    this.refs.ca.next();
  }

  show = () => {
    this.setState({display: "block"})
  }

  disShow = () => {
    this.setState({display: "none"})
  }

  render() {
    return (
        // 需要调用组件的方法，就要用ref属性获取该组件
        <Carousel autoplay className="carousel" ref="ca">
          <div onMouseMove={this.show} onMouseOut={this.disShow}>
            <h2>Hbuilder</h2>
            <p>415万开发者的选择</p>
            <Button className="button">了解更多</Button>
            <img src={dnImg} alt="1"></img>

         
            <div className="left" style={this.state} onClick={this.Prev}></div>
            <div className="right" style={this.state} onClick={this.Next}></div>
            
          </div>

          <div onMouseMove={this.show} onMouseOut={this.disShow}> 
            <h2>10亿手机用户</h2>
            <p>在使用DCloud工具开发发应用</p>
            <Button className="button">了解更多</Button>
            <img src={dnImg} alt="1"></img>

            <div className="left" style={this.state} onClick={this.Prev}></div>
            <div className="right" style={this.state} onClick={this.Next}></div>
          </div>
        </Carousel>
    )
  }
}
