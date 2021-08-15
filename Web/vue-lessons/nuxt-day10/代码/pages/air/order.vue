<template>
    <div class="container">
        <el-row type="flex" justify="space-between">
            <!-- 订单表单 -->
            <OrderForm/>

            <!-- 侧边栏 -->
            <OrderAside :data="$store.state.air.flightData"/>
        </el-row>
    </div>
</template>

<script>
// 购买机票的表单组件
import OrderForm from "@/components/air/orderForm"
// 机票订单的侧边栏组件
import OrderAside from "@/components/air/orderAside"

export default {
    components: {
        OrderForm,
        OrderAside
    }
}
</script>

<style lang="less" scoped>
    .container{
        width:1000px;
        margin:20px auto;
    }
    
    /*aside*/
    .aside{
        width: 350px;
        height: fit-content;
        border:1px #ddd solid;
    }
</style>