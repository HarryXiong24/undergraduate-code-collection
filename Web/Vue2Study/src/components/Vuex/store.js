import Vue from 'vue'
import Vuex from 'vuex'

// 在一个模块化的打包系统中,必须显式地通过 Vue.use() 来安装 Vuex：
Vue.use(Vuex)

// 使用Vue.Store
export default new Vuex.Store({
  // 状态对象
  state: {
    count: 0
  },
  // 包含多个更新state函数的对象,mutations对象里的方法可以直接操作state对象
  mutations: {
    // 工程中一般这些模块都是分开文件写,所以传入state参数的写法比较好
    // 如果有其他参数则可以往后写
    INCREMENT (state) {
      state.count++
    },
    DECREMENT (state) {
      state.count--
    }
  },
  // 包含多个对应事件回调函数的对象,actions对象里的方法用来接收组件信息,同时传递给mutations
  actions: {
    // 如果有其他参数则可以往对象后面写,称作载荷(payload)
    increment ({commit}) {
      commit('INCREMENT')
    },
    decrement ({commit}) {
      commit('DECREMENT')
    },
    incrementIfOdd ({commit, state}) {
      if (state.count % 2 !== 0) {
        commit('INCREMENT')
      }
    },
    incrementAsync ({commit}) {
      // 在action里直接可以写异步代码
      setInterval(() => {
        commit('INCREMENT')
      }, 1000)
    }
  },
  // 包含多个getter计算属性的函数对象
  getters: {
    evenOrOdd: function (state) {
      if (state.count % 2 !== 0) {
        return 'Odd'
      } else {
        return 'Even'
      }
    }
  }
})
