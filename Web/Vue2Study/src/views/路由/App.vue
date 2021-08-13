<template>
  <div>
    <div class="row">
      <div class="col-xs-offset-2 col-xs-8">
        <div class="page-header">
          <h2>Router Test</h2>
        </div>
      </div>
    </div>

    <div class="row">
      <div class="col-xs-2 col-xs-offset-2">
        <div class="list-group">
          <!--生成路由链接-->
          <router-link to="/About" class="list-group-item">About</router-link>
          <router-link to="/Home" class="list-group-item">Home</router-link>
        </div>
      </div>
      <div class="col-xs-6">
        <div class="panel">
          <div class="panel-body">
            <!-- 路由是跳转到其他路由时就会销毁的,使用keep-alive让其不被销毁 -->
            <keep-alive>
              <!--显示当前组件-->
              <router-view></router-view>
            </keep-alive>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import './css/index.css'
export default {
}
</script>

<style>
</style>
