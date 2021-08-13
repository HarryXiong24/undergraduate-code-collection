<template>
   <div class="todo-footer">
      <label>
        <input type="checkbox" v-model="check"/>
      </label>
      <span>
        <span>已完成{{completed}} / 全部{{items.length}}</span>
      </span>
      <button class="btn btn-danger" @click="del" v-show="completed > 0">清除已完成任务</button>
    </div>
</template>

<script>
  export default {
    props: {
      items: Array,
      setChooseAll: Function
    },
    computed: {
      completed: function () {
        let sum = 0
        for (let i = 0; i < this.items.length; i++) {
          if (this.items[i].complete === true) {
            sum = sum + 1
          }
        }
        return sum
      },
      check: {
        // 需要读取当前属性值的时候进行回调
        get: function () {
          return this.completed === this.items.length && this.completed > 0
        },
        // 当属性值发生改变的时候进行回调，更新相关数据
        set: function (value) {
          this.setChooseAll(value)
        }
      }
    },
    methods: {
      del () {
        if (window.confirm('Do you want to delete all?')) {
          this.$emit('delChooseItem')
        }
      }
    }
  }
</script>

<style>

</style>
