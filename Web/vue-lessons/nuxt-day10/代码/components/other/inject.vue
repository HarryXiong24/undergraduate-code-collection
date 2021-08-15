<template>
    <div>
        <!-- 依赖注入的子组件 -->
        依赖注入的子组件
        <p>{{message}}</p>
    </div>
</template>

<script>
export default {
    // 注入了父组件的数据
    inject: ['message'],
    mounted(){
        this.message = "123"
    }
};
</script>

<style>
</style>