<template>
    <!-- 组件递归 -->
    <div style="padding:100px;" >
        <MenuItem :data="list"/>
    </div>
</template>

<script>
import MenuItem from "@/components/other/menu-item"
export default {
    components: {
        MenuItem
    },
    data(){
        return {
            // 一个页面需不需要通过递归的方式展示出来，重点在于看数据的格式
            // 当我们不确定数据下面到底有多少级的时候，就需要使用递归!!!!!!!!!!!!!
            // 假设后台返回了以下数据格式
            list: [
                {
                    label: "衣服",
                    children: [
                        {
                            label: "男装",
                            children: [
                                { 
                                    label: "上衣"
                                },
                                { 
                                    label: "裤子"
                                }
                            ]
                        },
                        {
                            label: "女装",
                            children: [
                                { 
                                    label: "裙子"
                                }
                            ]
                        }
                    ]
                }, {
                    label: "电器",
                    children: [
                        { 
                            label: "冰箱"
                        },
                        { 
                            label: "空调"
                        }
                    ]
                }
            ]
        }
    }
};
</script>

<style>
.item  div{
    padding-left: 20px;
}
</style>