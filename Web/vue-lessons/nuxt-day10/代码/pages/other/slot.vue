<template>
    <div style="padding: 100px">
        <!-- 单标签的调用方式 -->
        <!-- <SlotChild/> -->

        <!-- 双标签调用组件的方式 -->
        <xy-button>确定</xy-button>
    </div>
</template>
<script>
// 子组件
import xybutton from "@/components/other/xy-button"

export default {
    components: {
        "xy-button": xybutton
    }
}
</script>