<template>
  <h1>{{ msg }}</h1>
  <p>Part 1</p>
  <button @click="add">count is: {{ count.name }}</button>
  <button @click="subtract">count is: {{ count.name }}</button>
</template>

<script>
// 使用前必须要引入
import { reactive, ref } from 'vue'
// 可以使用isRef, isReactive判断它们是ref还是reactive
import {isRef, isReactive} from 'vue'

export default {
  name: 'HelloWorld',
  props: {
    msg: String
  },
  data() {
    return {

    }
  },
  methods: {
    subtract() {
      // this.add() // 可以调用setup里的函数
      this.count.name--; // 可以调用setup里的变量
      console.log(this.count)
    }
  },

  /**
   * setup函数执行时间在beforecreated之前，所以没有this(this默认为undefined)，不能调用data中的数据
   * 但是在methods中，可以使用setup创建的变量，函数等，但要使用this
   * 本质是setup函数之后就会分别注入到data，methods中
   */
  setup() {

    /**
     * ref一般用来表示基础类型变量
     * ref本质就是产生了一个reactive对象
     * let count = ref(0) => let count = reactive({value: 0})
     * ref时打印变量会显示__v_isRef: true
     */
    // let count = ref({
    //   name: 0
    // });

    // function add() {
    //   count.value.name++;
    //   console.log(count);
    // }

    /** 
     * reactive里必须跟一个对象或者数组
     * 采用ES6中的proxy进行代理
     */
    // let count = reactive({
    //   name: 0
    // })

    // function add() {
    //   count.name++;
    //   console.log(count);
    // }

    /**
     * 组合API的好处就是将变量和对应处理函数整合在一起，避免Optio API方式不好管理的问题
     * 这将就可以将一整套相关的功能代码抽离出去，方便维护
     */
    let {count, add} = counter()

    // 一定要暴露出去，不然不能使用
    return {count, add}
  }
}

function counter() {
  let count = reactive({
    name: 0
  })

  function add() {
    count.name++;
    console.log(count);
  }

  return {count, add}
}

</script>
