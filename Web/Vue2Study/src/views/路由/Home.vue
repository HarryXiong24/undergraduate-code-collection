<template>
  <div>
    <h2>Home</h2>
    <ul>
      <router-link to="/Home/News">News</router-link>
      <router-link to="/Home/Message">Message</router-link>
    </ul>
    <hr>
    <div>
      <router-view></router-view>
    </div>
  </div>
</template>

<script>
  export default {}
</script>

<style>
</style>
