<template>
    <!-- 过滤器 -->
    <div style="padding: 100px">
        <h2 style="padding-bottom: 20px">过滤器</h2>

        <!-- 推荐用这个方式  -->
        <!-- <p>
            {{ Number(price).toFixed(2) }}
        </p> -->

        <!-- 1.在插值表达式中，竖线表示后面可以接上过滤器函数，tofixed就是一个过滤器的函数 -->
        <!-- price的值会经过tofixed的改造，最终展示出过滤器return的值 -->
        <p> {{ price | tofixed }} </p>
    </div>
</template>

<script>
export default {
    data(){
        return {
            price: 99
        }
    },
    // 2.过滤器函数
    filters: {
        // value参数就是使用了改过滤器的值
        tofixed(value){
            return Number(value).toFixed(4);
        }
    }
}
</script>

<style>

</style>