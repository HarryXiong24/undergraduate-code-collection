<template>
  <ul>
    <li v-for="(item, index) in news" :key="index">{{item}}</li>
  </ul>
</template>

<script>
export default {
  data () {
    return {
      news: ['new001', 'new002', 'new003']
    }
  }
}
</script>

<style>

</style>
