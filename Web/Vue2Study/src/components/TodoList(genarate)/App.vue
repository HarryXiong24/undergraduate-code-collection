<template>
  <div class="todo-container">
    <div class="todo-wrap">
      <myHeader @addItem="addItem"></myHeader>
      <myMain :items="items"></myMain>
      <myFooter :items="items" @delChooseItem="delChooseItem" :setChooseAll="setChooseAll"></myFooter>
    </div>
   </div>
</template>

<script>
  import myHeader from './myHeader'
  import myMain from './myMain'
  import myFooter from './myFooter'
  import './css/index.css'
  import Storage from './util/Storage'
  import Pubsub from 'pubsub-js'

  export default {
    data () {
      return {
        // 该属性为一个对象，格式{item: 表示做事的内容, complete: 表示是否完成，默认false}
        items: Storage.getData()
      }
    },
    components: {
      myHeader,
      myMain,
      myFooter
    },
    methods: {
      // 向items中新增数据
      addItem (value) {
        const newItem = {name: value, complete: false}
        this.items.push(newItem)
      },
      // 向items中删除已知位置的数据
      delItem (index) {
        this.items.splice(index, 1)
      },
      // 选择所有item
      setChooseAll (value) {
        if (value === true) {
          for (let i = 0; i < this.items.length; i++) {
            this.items[i].complete = true
          }
        } else {
          for (let i = 0; i < this.items.length; i++) {
            this.items[i].complete = false
          }
        }
      },
      // 删除选中的所有项目
      delChooseItem () {
        this.items = this.items.filter((item) => {
          return item.complete === false
        })
      }
    },
    watch: {
      // 深度监视，确保数据实时更新
      items: {
        deep: true,
        handler: function (value) {
          Storage.savaData(value)
        }
      }
    },
    mounted () {
      // 挂载订阅的delItem事件
      Pubsub.subscribe('delItem', (msg, index) => {
        this.delItem(index)
      })
    }
  }
</script>

<style>

</style>
