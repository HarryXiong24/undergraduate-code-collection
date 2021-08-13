// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'

// import App from './components/评论管理/App'

// import App from './components/TodoList/App'

// import App from './components/Ajax/App'

// import router from './router/index' // 导入路由器
// import App from './views/路由/App.vue'

// import store from './components/Vuex/store'
// import App from './components/Vuex/App.vue'

// import App from './components/TodoList(Vuex)/App'
// import store from './components/TodoList(Vuex)/store/index'

import App from '../src/components/vue-chart/App.vue'

Vue.config.productionTip = false

/* eslint-disable no-new */
new Vue({
  el: '#app',
  // components: { App },
  // template: '<App/>',
  // 也可以简写成router(ES语法)
  // router: router,
  // 所有的组件都多了一个属性$store
  store: store,
  // 原理
  /**
   * render: (h) => {
   *  return <APP></APP>
   * }
   */
  // 可以代替components和template
  render: h => h(App)
})
