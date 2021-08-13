<template>
  <li class="list-group-item">
    <div class="handle">
      <input type="checkbox" v-model="item.del" v-show="show === true">
      <button @click="remove">删除</button>
    </div>
    <p class="user">
      <span>{{item.name}}</span>
      <span>说:</span>
    </p>
    <p class="centence">{{item.content}}</p>
  </li>
</template>

<script>
  import Pubsub from 'pubsub-js'
  export default {
    props: {
      item: Object,
      index: Number,
      show: Boolean
    },
    methods: {
      remove () {
        Pubsub.publish('deleteComment', this.index)
      }
    }
  }
</script>

<style></style>
