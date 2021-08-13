/**
 * 路由器模块
 * 配置所有的路由
 */
import Vue from 'vue'
import VueRouter from 'vue-router'
import About from '../views/路由/About.vue'
import Home from '../views/路由/Home.vue'
import News from '../views/路由/News.vue'
import Message from '../views/路由/Message.vue'
import MsgDetail from '../views/路由/MsgDetail.vue'

// 如果在一个模块化工程中使用它,必须要通过Vue.use()明确地安装路由功能
Vue.use(VueRouter)
export default new VueRouter({
  // routes为一个数组对象
  routes: [
    {
      // 指定其跳转的位置
      path: '/About',
      // 指定其对应绑定的路由
      component: About
    },
    {
      path: '/Home',
      component: Home,
      // 子路由的定义方式
      children: [
        {
          // /在开头永远代表根路径
          path: '/Home/News',
          component: News
        },
        {
          // ''代表当前路径，所以'Message'为简写
          path: 'Message',
          component: Message,
          children: [
            {
              // :表示占位，一般用于params参数的使用
              path: '/Home/Message/MsgDetail/:id',
              component: MsgDetail
            }
          ]
        },
        {
          path: '',
          redirect: 'News'
        }
      ]
    },
    /**
     * 路由的重定向
     */
    {
      path: '/',
      redirect: '/About'
    }
  ]
})
