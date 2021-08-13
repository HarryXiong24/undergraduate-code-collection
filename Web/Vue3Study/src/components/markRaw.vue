<template>
  <div>
    <p>Part 4</p>
    <p>{{state}}</p>
  </div>
</template>

<script>
import { ref, toRaw, reactive, markRaw } from 'vue';

export default {
  name: 'toxxx',
  setup() {

    /**
     * 标记一个对象，使其永远不会转换为代理。返回对象本身。
     */
    let obj = markRaw({
      name: "harry",
      age: 20
    })

    // 不起代理作用，返回结果仍然是对象本身
    let state = reactive(obj)

    // console.log(state)

    return {state}
  }
}

</script>

<style>

</style>