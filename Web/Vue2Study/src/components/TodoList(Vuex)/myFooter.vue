<template>
   <div class="todo-footer">
      <label>
        <input type="checkbox" v-model="check"/>
      </label>
      <span>
        <span>已完成{{$store.getters.completed}} / 全部{{$store.state.items.length}}</span>
      </span>
      <button class="btn btn-danger" @click="del" v-show="$store.getters.completed > 0">清除已完成任务</button>
    </div>
</template>

<script>
  export default {
    computed: {
      check: {
        // 需要读取当前属性值的时候进行回调
        get: function () {
          return this.$store.getters.toCheck
        },
        // 当属性值发生改变的时候进行回调，更新相关数据
        set: function (value) {
          this.$store.dispatch('setChooseAll', value)
        }
      }
    },
    methods: {
      del () {
        if (window.confirm('Do you want to delete all?')) {
          this.$store.dispatch('delChooseItem')
        }
      }
    }
  }
</script>

<style>

</style>
