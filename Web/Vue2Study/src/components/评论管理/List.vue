<template>
  <div class="col-md-8 col-lg-8" id="list">
    <div style="width: 870px; height: 40px">
      <h3 class="reply">评论回复：</h3>
      <div class="button">
        <button v-if="!show" @click="delChoose">批量删除</button>
        <div v-else>
          <button @click="delChoose">取消批量删除</button>
          <button @click="del">确定删除</button>
          <span v-show="show">选中 {{count}} / 共 {{comments.length}}</span>
        </div>
      </div>
    </div>
    <h2 v-show="comments.length === 0">暂无评论，点击左侧添加评论！！！</h2>
    <ul class="list-group">
      <Item v-for="(item, index) in comments" :key="index" :item="item" :show="show">
      </Item>
    </ul>
  </div>
</template>

<script>
  import Item from './Item'

  export default {
    data () {
      return {
        ItemChoose: [],
        show: false
      }
    },
    components: {
      Item
    },
    props: {
      comments: Array
    },
    methods: {
      delChoose () {
        this.show = !this.show
      },
      del () {
        if (window.confirm('Do you want to delete?')) {
          this.$emit('delConfirm')
        }
      }
    },
    computed: {
      count: function () {
        let sum = 0
        for (let i = 0; i < this.comments.length; i++) {
          if (this.comments[i].del === true) {
            sum++
          }
        }
        return sum
      }
    }
  }
</script>

<style>
  .reply {
    margin-top: 0px;
  }

  li {
    transition: .5s;
    overflow: hidden;
  }

  .handle {
    width: 80px;
    background: #fff;
    position: absolute;
    right: 10px;
    top: 1px;
    text-align: center;
  }

  .handle a {
    display: block;
    text-decoration: none;
  }

  .list-group-item .centence {
    padding: 0px 50px;
  }

  .user {
    font-size: 22px;
  }

  .button {
    float: right;
    margin-top: 5px;
  }
  h3 {
    float: left;
    display: block;
  }
</style>
