import React from "react";
import dcloudImg from "./img/dcloud.png";

export default class Footer extends React.Component {
    render() {
        return (
            <div className="footer">
                <img src={dcloudImg} alt="1"></img>
                <p className="mui-pull-left">DCloud 即数字天堂(北京)网络技术有限公司是
                    <a href="//www.w3.org/"> W3C </a>成员及
                    <a href="//www.html5plus.org/" className="color3">HTML5中国产业联盟 </a>发起单位
				</p>
                <div className="right">
                    <p>蒙ICP备14002744号-1</p>
                </div>
            </div>
        )
    }
}