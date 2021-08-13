<template>
  <ul class="todo-main">
    <Item v-for="(item, index) in $store.state.items" :key="index" :index="index" :item="item"></Item>
  </ul>
</template>

<script>
  import Item from './Item'

  export default {
    components: {
      Item
    }
  }
</script>

<style>

</style>
