<template>
  <ul class="todo-main">
    <Item v-for="(item, index) in items" :key="index" :index="index" :item="item"></Item>
  </ul>
</template>

<script>
  import Item from './Item'
  export default {
    props: {
      items: Array
    },
    components: {
      Item
    }
  }
</script>

<style>

</style>
