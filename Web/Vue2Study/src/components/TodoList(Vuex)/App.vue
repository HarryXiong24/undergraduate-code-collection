<template>
  <div class="todo-container">
    <div class="todo-wrap">
      <myHeader></myHeader>
      <myMain></myMain>
      <myFooter></myFooter>
    </div>
   </div>
</template>

<script>
  import myHeader from './myHeader'
  import myMain from './myMain'
  import myFooter from './myFooter'
  import './css/index.css'
  import { mapState } from 'vuex'
  import Storage from './util/Storage'

  export default {
    components: {
      myHeader,
      myMain,
      myFooter
    },
    mounted () {
      this.$store.dispatch('updateItems')
    },
    computed: {
      ...mapState(['items'])
    },
    watch: {
      // 深度监视，确保数据实时更新
      items: {
        deep: true,
        handler: function (value) {
          Storage.savaData(value)
        }
      }
    }
  }
</script>

<style>

</style>
