<template>
    <div style="padding: 100px">
        依赖注入的父组件

        <Inject/>
    </div>
</template>

<script>
import Inject from "@/components/other/inject";

export default {
    // 依赖注入里父组件提供的数据, 这个数据是要注入到子组件中
    provide: {
        message: "hello",
        a: 1,
        b: 2,
        c: 3
    },
    components: {
        Inject
    }
};
</script>

<style>
</style>