<template>
  <li @mouseenter="handleColor(true)" @mouseleave="handleColor(false)" :style="{backgroundColor: bgColor}">
    <label>
      <input type="checkbox" v-model="item.complete"/>
      <span>{{item.name}}</span>
    </label>
    <button class="btn btn-danger" @click="del" v-show="item.complete === true">删除</button>
  </li>
</template>

<script>
  import Pubsub from 'pubsub-js'
  export default {
    data () {
      return {
        bgColor: 'white'
      }
    },
    props: {
      item: Object,
      index: Number
    },
    methods: {
      del () {
        if (window.confirm('Do you want to delete it?')) {
          Pubsub.publish('delItem', this.index)
        }
      },
      handleColor (value) {
        if (value === true) {
          this.bgColor = '#aaaaaa'
        } else {
          this.bgColor = 'white'
        }
      }
    }
  }
</script>

<style>

</style>
