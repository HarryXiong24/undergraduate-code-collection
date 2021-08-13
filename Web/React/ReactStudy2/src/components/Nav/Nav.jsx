import React from 'react'
import { Menu } from 'antd';
import { MailOutlined, AppstoreOutlined, SettingOutlined } from '@ant-design/icons';
import { NavLink } from 'react-router-dom/cjs/react-router-dom.min';

const { SubMenu } = Menu;

class Nav extends React.Component {
  
  state = {
    current: 'mail',
  };

  handleClick = e => {
    console.log('click ', e);
    this.setState({ current: e.key });
  };

  render() {
    const { current } = this.state;
    return (
      <Menu onClick={this.handleClick} selectedKeys={[current]} mode="horizontal">

        <Menu.Item key="page1" icon={<MailOutlined />}>
          <NavLink to="/page1">Page1</NavLink>
        </Menu.Item>

        <Menu.Item key="page2" icon={<AppstoreOutlined />}>
          <NavLink to="/page2">Page2</NavLink>
        </Menu.Item>

      </Menu>
    );
  }
}

export default Nav