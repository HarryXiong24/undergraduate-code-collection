<template>
    <!-- 自定义指令 -->
    <div style="padding: 100px;">
        <!-- 自定义指令的作用就是用来获取dom元素，其实一般都是使用ref就可以了 -->
        <div v-red class="box"></div>
    </div>
</template>

<script>
export default {
    // 1.声明自定义指令
    directives: {
        red: {
            // 调用该指令的节点元素，在加载后执行
            inserted: function (el) {
                el.style.background = "red";
            }
        }
    }
}
</script>

<style scoped>
.box{
    width: 200px;
    height: 200px;
    background: gray
}
</style>