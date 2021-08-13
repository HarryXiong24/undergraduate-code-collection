import React from "react";
import axios from "axios";

/**
 * 该组件的作用是通过接收父组件传进来的searchName参数，用axios向浏览器实时发送GET请求
 */
export default class Show extends React.Component {
    constructor() {
        super();
        this.state = {
            //开始
            firstView: true,
            //加载中
            loading: false,
            //搜素成功
            users: null,
            //搜索失败
            error: null
        }
    }
    /**
     * 由于是先根据用户输入的searchName，进行搜索。所以要使用componentWillReceiveProps(nextProps)方法
     * 在这个回调函数里面，你可以根据属性的变化，通过调用this.setState()来更新你的组件状态
     * 其中:
     * nextProps代表这次的props值，this.props代表上次props的值
     */
    componentWillReceiveProps(nextProps) {
        let searchName = nextProps.searchName
        console.log('发送ajax请求', searchName)
        const url = `https://api.github.com/search/users?q=${searchName}`
        this.setState({
            firstView: false,
            loading: true
        })

        // 使用axios库,axios是基于Promise对象写的
        axios.get(url)
            .then((response) => {
                console.log(response)
                this.setState({ loading: false, users: response.data.items })
            })
            // catch()方法用来获取错误
            .catch((error) => {
                // debugger
                console.log(error)
                this.setState({ loading: false, error: error.message })
            })
    }

    render() {
        if (this.state.firstView === true) {
            return (
                <h2>Enter name to search</h2>
            )
        }
        else if (this.state.loading === true) {
            return (
                <h2>Loading...</h2>
            )
        }
        else if (this.state.users) {
            const users = this.state.users;
            return (
                <div className="row">
                    {
                        users.map((user, index) => (
                            <div className="card" key={user.html_url}>
                                <a href={user.html_url} target="_blank" rel="noopener noreferrer">
                                    <img src={user.avatar_url} style={{ width: '100px' }} alt='user' />
                                </a>
                                <p className="card-text">{user.login}</p>
                            </div>
                        ))
                    }
                </div>
            )
        }
        else if (this.state.error) {
            return (
                <h2>Research fail!</h2>
            )
        }
    }
}
