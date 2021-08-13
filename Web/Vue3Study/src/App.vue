<template>
  <img alt="Vue logo" src="./assets/logo.png" />
  <HelloWorld msg="Hello Vue 3.0 + Vite" />
  <Recursion></Recursion>
  <toRaw></toRaw>
  <markRaw></markRaw>
  <toRef></toRef>
</template>

<script>

import HelloWorld from './components/HelloWorld.vue'
import markRaw from './components/markRaw.vue'
import Recursion from './components/Recursion.vue'
import toRaw from './components/toRaw.vue'
import toRef from './components/toRef_toRefs.vue'

export default {
  name: 'App',
  components: {
    HelloWorld,
    Recursion,
    toRaw,
    markRaw,
    toRef,
  }
}
</script>
