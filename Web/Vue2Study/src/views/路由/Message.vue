<template>
  <div>
    <ul>
      <li v-for="(mes) in msg" :key="mes.id" @click="saveMsg(mes)">
        <router-link :to="`/Home/Message/MsgDetail/${mes.id}`">{{mes.title}}</router-link>
        <button @click="pushshow(mes.id)">PushShow</button>
        <button @click="replaceShow(mes.id)">ReplaceShow</button>
      </li>
    </ul>
    <button @click="$router.back()">Back</button>
    <hr>
    <router-view :message="message"></router-view>
  </div>
</template>

<script>
export default {
  data () {
    return {
      msg: [
        {id: 1, title: 'message01', content: 'sfhsgjasfjkf'},
        {id: 2, title: 'message02', content: 'sfhsgjasfjkf'},
        {id: 3, title: 'message03', content: 'sfhsgjasfjkf'},
        {id: 4, title: 'message04', content: 'sfhsgjasfjkf'}
      ],
      message: {}
    }
  },
  methods: {
    saveMsg (value) {
      this.message = value
    },
    pushshow (value) {
      this.$router.push(`/Home/Message/MsgDetail/${value}`)
    },
    replaceShow (value) {
      this.$router.replace(`/Home/Message/MsgDetail/${value}`)
    }
  }
}
</script>

<style>

</style>
