import React from "react";
import { Menu } from 'antd';
import logoImg from "./img/logo.png";
import hxImg from "./img/hx.png";
import uniImg from "./img/uni.png";
import uniCloudImg from "./img/uniCloud.png";
import wImg from "./img/w.png";
import muiImg from "./img/mui.png";
import p5Img from "./img/5.png"
import pImg from "./img/p.png";
import sImg from "./img/s.png";
import uniadImg from "./img/p.png";




export default class Nav extends React.Component {
    state = {
        current: 'mail',
      };
    
    handleClick = e => {
    console.log('click ', e);
    this.setState({
        current: e.key,
    });
    };


    render() {
        return (
            <div id="nav">
                <div className="top">

                    <div className="logo">
                        <img src={logoImg} alt="logo"></img>
                    </div>

                    <Menu onClick={this.handleClick} selectedKeys={[this.state.current]} mode="horizontal" className="Items">
                        <Menu.Item key="head">首页</Menu.Item>
                        <Menu.Item key="text">文档</Menu.Item>
                        <Menu.Item key="community">社区</Menu.Item>
                        <Menu.Item key="plugin">插件市场</Menu.Item>
                        <Menu.Item key="example">案例</Menu.Item>
                        <Menu.Item key="permission">商业许可</Menu.Item>
                        <Menu.Item key="intellect">求贤</Menu.Item>
                        <Menu.Item key="league">联盟</Menu.Item>
                        <Menu.Item key="background">开发者后台</Menu.Item>
                    </Menu>

                </div>

                <div className="bottom">
                    <div className="title1">
                        <h4>开发服务</h4>
                        <span>帮你做好应用</span>
                    </div>
                    <div>
                        <img src={hxImg} alt="hx"></img>
                        <h4>Hbuilder</h4>
                        <span>极客开发工具</span>
                    </div> 
                    <div>
                        <img src={uniImg} alt="uni"></img>
                        <h4>uni-app</h4>
                        <span>开发一次，多端覆盖</span>
                    </div>
                    <div>
                        <img src={uniCloudImg} alt="uni"></img>
                        <h4>uniCloud</h4>
                        <span>云开发平台</span>
                    </div>
                    <div>
                        <img src={wImg} alt="uni"></img>
                        <h4>wap2app</h4>
                        <span>M站快速转换App</span>
                    </div>
                    <div>
                        <img src={muiImg} alt="uni"></img>
                        <h4>MUI</h4>
                        <span>上万Star的前端框架</span>
                    </div>
                    <div>
                        <img src={p5Img} alt="uni"></img>
                        <h4>5+Runtime</h4>
                        <span>增强HTML5的功能体验</span>
                    </div>

                    <div className="title2">
                        <h4>运营服务</h4>
                        <span>帮你运营好应用</span>
                    </div>
                    <div>
                        <img src={pImg} alt="uni"></img>
                        <h4>广告联盟uni-AD</h4>
                        <span>帮助开发者变现</span>
                    </div>
                    <div>
                        <img src={sImg} alt="uni"></img>
                        <h4>uni统计</h4>
                        <span>跨端追踪，助力增长</span>
                    </div>
                    <div>
                        <img src={uniadImg} alt="uni"></img>
                        <h4>应用发行平台</h4>
                        <span>帮助开发者获取用户</span>
                    </div>

                </div>

            </div>
            );
    }
}