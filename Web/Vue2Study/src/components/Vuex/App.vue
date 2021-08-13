<template>
  <div>
    <!-- 任何一个组件里都会有一个$store对象,里面有state,getters属性 -->
    <p>Count {{count}} & count is {{evenOrOdd}}</p>
    <button @click="increment">+</button>
    <button @click="decrement">-</button>
    <button @click="incrementIfOdd">increment if odd</button>
    <button @click="incrementAsync">increment async</button>
  </div>
</template>

<script>
// 这些分别为常用的组件绑定的辅助函数
import {mapGetters, mapActions, mapState} from 'vuex'
export default {
  computed: {
    // 等价于mapGetters()返回值为{evenOrOdd(){return this.$store.getters['evenOrOdd']}}
    ...mapGetters(['evenOrOdd']),
    // 等价于mapState()返回值{count(){return this.$store['count']}}
    ...mapState(['count'])
  },
  methods: {
    // 其中这三个方法也可以传入一个对象而非数组,例如：
    // mapActions({Increment: 'increment'})
    // 把 `this.Increment` 映射为 `this.$store.getters.increment`
    // 意思就是给getters里的属性取一个不同于increment的名字
    ...mapActions(['increment', 'decrement', 'incrementIfOdd', 'incrementAsync'])
  }
}
</script>

<style>

</style>
