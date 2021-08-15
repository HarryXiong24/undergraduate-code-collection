<template>
    <!-- 混入.混入一般用于多个组件公用一份数据或者函数 -->
    <div style="padding: 100px"> 
        混合的组件1: {{message}}
    </div>
</template>
<script>
// 导入公共的混入的数据
import mixin from "@/assets/mixin"

export default {
    // 混入数据
    mixins: [mixin]
}
</script>