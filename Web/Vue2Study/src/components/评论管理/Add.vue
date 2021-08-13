<template>
  <div class="col-md-4 col-lg-4" id="add">
    <form class="form-horizontal">
      <div class="form-group">
        <label>用户名</label>
        <input type="text" class="form-control" placeholder="用户名" v-model="name" />
      </div>
      <div class="form-group">
        <label>评论内容</label>
        <textarea class="form-control" rows="6" placeholder="评论内容" v-model="content" @keyup.enter="submit"></textarea>
      </div>
      <div class="form-group">
        <div class="col-sm-offset-2 col-sm-10">
          <button type="button" class="btn btn-default pull-right" @click="submit">提交</button>
        </div>
      </div>
    </form>
  </div>
</template>

<script>
export default {
  data () {
    return {
      name: '',
      content: ''
    }
  },
  methods: {
    submit () {
        const name = this.name.trim()
        const content = this.content.trim()
        const del = false
        if (!this.name || !this.content) {
          alert('Input error!')
          return 0
        }
        const newComment = {name, content, del}
        this.$emit('addComment', newComment)

        this.name = ''
        this.content = ''
    }
  }
}
</script>

<style>
</style>
