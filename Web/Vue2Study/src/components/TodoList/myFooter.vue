<template>
   <div class="todo-footer">
      <label>
        <!-- <input type="checkbox" v-model="check"/> -->
        <!-- 构造插槽进行占位 -->
        <slot name="checkAll"></slot>
      </label>
      <span>
        <!-- <span>已完成{{completed}} / 全部{{items.length}}</span> -->
        <!-- 构造插槽进行占位 -->
        <slot name="count"></slot>
      </span>
      <!-- <button class="btn btn-danger" @click="del" v-show="completed > 0">清除已完成任务</button> -->
      <!-- 构造插槽进行占位 -->
      <slot name="delButton"></slot>
    </div>
</template>

<script>
  export default {
  }
</script>

<style>

</style>
