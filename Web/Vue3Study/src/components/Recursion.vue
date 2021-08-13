<template>
  <div>
    <p>Part 2</p>
    <p>{{state.head}}</p>
    <p>{{state.a.aa}}</p>
    <p>{{state.a.b.bb}}</p>
    <p>{{state.a.b.c.cc}}</p>
    <p>{{state.a.b.c.d.dd}}</p>
  </div>
  <button @click="click">Click</button>
</template>

<script>
import { reactive, ref, shallowReactive, shallowRef, triggerRef } from 'vue'

export default {
  name: 'Recursion',
  setup() {
    
    /**
     * reactive是会进行递归监听的，即对象里每一个成员都会proxy代理
     * 这样对于嵌套过多的变量，很消耗性能
     */
    // let state = reactive({
    //   a: {
    //     aa: 1,
    //     b: {
    //       bb: 2,
    //       c: {
    //         cc: 3,
    //         d: {
    //           dd: 4
    //         }
    //       }
    //     },
    //   }
    // })

    // function click() {
    //   console.log(state);
    //   console.log(state.a);
    //   console.log(state.a.b);
    //   console.log(state.a.b.c);
    //   console.log(state.a.b.c.d);
    // }

    /**
     * 同理，ref也会进行递归监听
     */
    // let state = ref({
    //   a: {
    //     aa: 1,
    //     b: {
    //       bb: 2,
    //       c: {
    //         cc: 3,
    //         d: {
    //           dd: 4
    //         }
    //       }
    //     },
    //   }
    // })

    // function click() {
    //   console.log(state);
    //   console.log(state.value);
    //   console.log(state.value.a);
    //   console.log(state.value.a.b);
    //   console.log(state.value.a.b.c);
    //   console.log(state.value.a.b.c.d);
    // }

    /**
     * 为了防止出现递归监听，vue3.0提供了shallowReactive, shallowRef
     * 作用就是浅监听，只监听数据的第一层
     */
    // let state = shallowReactive({
    //   head: 0,
    //   a: {
    //     aa: 1,
    //     b: {
    //       bb: 2,
    //       c: {
    //         cc: 3,
    //         d: {
    //           dd: 4
    //         }
    //       }
    //     },
    //   }
    // })

    // function click() {
    //   // 查看数据我们可以看到只有state有proxy，里层都是没有的
    //   console.log(state);
    //   console.log(state.a);
    //   console.log(state.a.b);
    //   console.log(state.a.b.c);
    //   console.log(state.a.b.c.d);

    //   // 此时修改值，如果把第一行注释，那么没有proxy将无法触发页面重新渲染
    //   // 如果不注释第一行，则state.head会触发重新渲染，所以后面的值页面上也会变
    //   state.head = 'head'
    //   state.a.aa = 'a'
    //   state.a.b.bb = 'b'
    //   state.a.b.c.cc = 'c'
    //   state.a.b.c.d.dd = 'd'

    //   console.log(state);
    //   console.log(state.a);
    //   console.log(state.a.b);
    //   console.log(state.a.b.c);
    //   console.log(state.a.b.c.d);
    // }

    /**
     * shallowRef是监听.value的变化，并不是监听第一层的变化
     * 但是shallowRef的本质仍然是shallowReactive
     */
    let state = shallowRef({
      head: 0,
      a: {
        aa: 1,
        b: {
          bb: 2,
          c: {
            cc: 3,
            d: {
              dd: 4
            }
          }
        },
      }
    })

    function click() {

      // 因为是监听.value的变化，所以修改第一层是没有用的，修改后面的层也更没有用
      state.value.head = 'head'
      state.value.a.aa = 'a'
      state.value.a.b.bb = 'b'
      state.value.a.b.c.cc = 'c'
      state.value.a.b.c.d.dd = 'd'

      // 所以我们必须修改.value
      // state.value = {
      //   head: 'head',
      //   a: {
      //     aa: 'a',
      //     b: {
      //       bb: 'b',
      //       c: {
      //         cc: 'c',
      //         d: {
      //           dd: 'd'
      //         }
      //       }
      //     },
      //   }
      // }

      // 当然，vue3.0给我们提供了一个方法triggerRef用来手动更新
      // 这样就可以直接进行修改了
      state.value.head = 'head'
      state.value.a.aa = 'a'
      state.value.a.b.bb = 'b'
      state.value.a.b.c.cc = 'c'
      state.value.a.b.c.d.dd = 'd'
      triggerRef(state)

      
      console.log(state);
      console.log(state.value);
      console.log(state.value.a);
      console.log(state.value.a.b);
      console.log(state.value.a.b.c);
      console.log(state.value.a.b.c.d);
    }

    return {state, click}
  }
}


</script>
