<template>
  <div class="card">
        <a :href="item.url" target="_blank">
          <img :src="item.avatarUrl" style='width: 100px'/>
        </a>
        <p class="card-text">{{item.username}}</p>
  </div>
</template>

<script>
export default {
  props: {
    item: Object
  }
}
</script>

<style>

</style>
