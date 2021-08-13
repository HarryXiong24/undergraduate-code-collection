<template>
  <div id="container">
    <header class="site-header jumbotron">
      <div class="container">
        <div class="row">
          <div class="col-xs-12">
            <h1>请发表对Vue的评论</h1>
          </div>
        </div>
      </div>
    </header>
    <div id="container">
      <Add @addComment="addComment"></Add>
      <List :comments="comments" @delConfirm="delConfirm"></List>
    </div>
  </div>
</template>

<script>
  import Add from './Add'
  import List from './List'
  import Storage from './util/Storage'
  import Pubsub from 'pubsub-js'

  export default {
    data () {
      return {
        comments: Storage.getData()
      }
    },
    methods: {
      addComment (content) {
        this.comments.unshift(content)
      },
      deleteComment (index) {
        if (window.confirm('Do you want to delete?')) {
          this.comments.splice(index, 1)
        }
      },
      delConfirm () {
        this.comments = this.comments.filter((item) => {
          return item.del === false
        })
      }
    },
    components: {
      Add,
      List
    },
    watch: {
      comments: {
        deep: true,
        handler: function (value) {
          Storage.saveData(value)
        }
      }
    },
    mounted () {
      Pubsub.subscribe('deleteComment', (msg, index) => {
        this.deleteComment(index)
      })
    }
  }
</script>

<style></style>
