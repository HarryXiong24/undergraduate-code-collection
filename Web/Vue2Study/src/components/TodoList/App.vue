<template>
  <div class="todo-container">
    <div class="todo-wrap">
      <myHeader @addItem="addItem"></myHeader>
      <!-- <myHeader ref="head"></myHeader> -->
      <myMain :items="items"></myMain>
      <myFooter :items="items" :delChoose="delChoose" :setChooseAll="setChooseAll">
        <!-- 填满插槽，用slot属性值对应子组件里name的属性值 -->
        <!-- 此时所有和插槽有关的数据，包括属性、方法，全部都应该放在这个组件里面，而不是子组件 -->
        <input slot="checkAll" type="checkbox" v-model="check"/>
        <span slot="count">已完成{{completed}} / 全部{{items.length}}</span>
        <button slot="delButton" class="btn btn-danger" @click="del" v-show="completed > 0">清除已完成任务</button>
      </myFooter>
    </div>
   </div>
</template>

<script>
  import myHeader from './myHeader'
  import myMain from './myMain'
  import myFooter from './myFooter'
  import './css/index.css'
  import Pubsub from 'pubsub-js'
  import Storage from './util/Storage'

  export default {
    data () {
      return {
        // 读取localStorage保存的数据
        // items: JSON.parse(localStorage.getItem('todos_key') || '[]')
        items: Storage.getData()
      }
    },
    components: {
      myHeader,
      myMain,
      myFooter
    },
    mounted () {
      // this.$refs.head.$on('addItem', this.addItem)
      Pubsub.subscribe('delItems', (msg, index) => {
        this.remove(index)
      })
    },
    methods: {
      addItem (newValue) {
        const newItem = {name: newValue, complete: false}
        this.items.push(newItem)
      },
      remove (index) {
        this.items.splice(index, 1)
      },
      delChoose () {
        this.items = this.items.filter(
          (item) => {
            return !item.complete
          }
        )
      },
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
      del () {
        if (window.confirm('Do you want to delete all?')) {
          this.delChoose()
        }
      }
    },
    watch: {
      items: {
        deep: true,
        handler: function (val) {
          // 将数据(json)保存到localStorage
          // localStorage.setItem('todos_key', JSON.stringify(val))
          Storage.savaData(val)
        }
      }
    },
    computed: {
      completed: function () {
        let sum = 0
        for (let i = 0; i < this.items.length; i++) {
          if (this.items[i].complete === true) {
            sum = sum + 1
          }
        }
        return sum
      },
       check: {
        get () {
          return this.completed === this.items.length && this.completed > 0
        },
        // 不推荐这种写法，在子组件中尽量不要去尝试修改父组件传进来的值
        // set (value) {
        //   if (value === true) {
        //     for (let i = 0; i < this.items.length; i++) {
        //       this.items[i].complete = true
        //     }
        //   } else {
        //     for (let i = 0; i < this.items.length; i++) {
        //       this.items[i].complete = false
        //     }
        //   }
        // }
        // 操作哪个组件参数的方法，就应该写在哪个组件里面
        set (value) {
          this.setChooseAll(value)
        }
      }
    }
  }
</script>

<style>

</style>
