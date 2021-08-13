<template>
  <div class="container">
    <section class="jumbotron">
      <h3 class="jumbotron-heading">Search Github Users</h3>
      <div>
        <input type="text" placeholder="enter the name you search" v-model="searchName"/>
        <button @click="search">Search</button>
      </div>
    </section>
    <div class="row">
      <showItem v-for="(item, index) in Items" :key="index" :item='item'></showItem>
    </div>
  </div>
</template>

<script>
  import './css/index.css'
  import showItem from './showItem'
  import axios from 'axios'
  export default {
    data () {
      return {
        searchName: '',
        Items: []
      }
    },
    components: {
      showItem
    },
    methods: {
      search () {
        const url = `https://api.github.com/search/users?q=${this.searchName}`
        axios.get(url)
        .then(res => {
          this.Items = res.data.items.map((item) => ({
            username: item.login,
            url: item.url,
            avatarUrl: item.avatarUrl
          }))
        })
        .catch(err => {
          console.error(err)
        })
      }
    }
  }
</script>

<style>

</style>
