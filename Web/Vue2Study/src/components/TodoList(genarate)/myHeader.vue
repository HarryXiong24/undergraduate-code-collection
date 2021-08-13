<template>
  <div class="todo-header">
    <input type="text" placeholder="请输入你的任务名称，按回车键确认" v-model="value" @keyup.enter="submit"/>
  </div>
</template>

<script>
  export default {
    data () {
      return {
        value: '' // 用户输入的todo内容
      }
    },
    methods: {
      // 点击以后调用App组件addItem方法处理新增加的值
      submit () {
        if (this.value.trim()) {
          this.$emit('addItem', this.value)
          this.value = ''
        }
      }
    }
  }
</script>

<style>

</style>
