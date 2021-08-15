
<template>
    <div class="item">
        <div v-for="(item, index) in data" :key="index" >
            {{item.label}}

            <!-- 在这个位置来自己调用自己 -->
            <menu-item :data="item.children"/>
        </div>
    </div>
</template>

<script>
export default {
    // 可以通过name属性来实现自己调用组件自己
    name: "menu-item",
    props: {
        // 组件接收的属性可以简写成这样，不需要带默认值
        data: Object
    }
};
</script>

<style  scoped>
.item  div{
    padding-left: 20px;
}
</style>