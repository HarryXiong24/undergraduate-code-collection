<template>
  <div>
    <p>Part 5</p>
    <p>{{state}}</p>
    <p>{{name}}</p>
  </div>
</template>

<script>
import { ref, toRaw, reactive, markRaw, toRef, toRefs } from 'vue';

export default {
  name: 'toxxx',
  setup() {
    
    let obj = {
      name: 'harry',
      age: 20
    }

    let name = toRef(obj, 'harry')

    let state = toRefs(obj)

    console.log(name)
    console.log(state);

    return {name, state}
  }
}

</script>

<style>

</style>