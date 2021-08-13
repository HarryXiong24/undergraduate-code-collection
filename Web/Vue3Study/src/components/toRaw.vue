<template>
  <div>
    <p>Part 3</p>
    <p>{{state}}</p>
    <p>{{number}}</p>
  </div>
</template>

<script>
import { ref, toRaw, reactive, markRaw } from 'vue';

export default {
  name: 'toxxx',
  setup() {

    let state = reactive({
      name: "harry",
      age: 20
    })

    let number = ref(100)

    /** 
     * toRaw用于提取出reactive对象的原始值，这样修改原始值就不会触发界面更新
     * 由于ref的本质也是reactive，所以toRaw也可以用于ref，只不过要加value
     */
    let obj1 = toRaw(state)
    let obj2 = toRaw(number.value)

    // console.log(state)
    // console.log(obj1)

    // console.log(number)
    // console.log(obj2)

    return {state, number}
  }
}

</script>

<style>

</style>