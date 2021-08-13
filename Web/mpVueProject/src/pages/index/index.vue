<template>
   <div class="indexContainer">
    <img  v-if="isShow" class="index_img" src="../../images/avatar" alt="">
    <Button class="btn" v-else open-type="getUserInfo" @getuserinfo="getUserInfo">点击获取用户信息</Button>
    <p class="userName">hello {{userInfo.nickName}}</p>
    <div @tap="toDetail" class="goStudy">
      <p>开启小程序之旅</p>
    </div>
  </div>
</template>

<script>
export default {

}
</script>

<style>

</style>
