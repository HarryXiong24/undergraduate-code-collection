<template>
  <div class="todo-header">
    <input type="text" placeholder="请输入你的任务名称，按回车键确认" v-model="value" @keyup.enter="submit"/>
  </div>
</template>

<script>
  export default {
    data () {
      return {
        value: ''
      }
    },
    props: {
      // addItem: Function
    },
    methods: {
      submit () {
        if (this.value.trim()) {
          // this.addItem(this.value)
          this.$emit('addItem', this.value)
          this.value = ''
        }
      }
    }
  }
</script>

<style>

</style>
