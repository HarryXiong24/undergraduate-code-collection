<template>
    <section class="contianer">
        <el-row  type="flex" justify="space-between">

            <!-- 顶部过滤列表 -->
            <div class="flights-content">
                <!-- 过滤条件 -->
                <div>
                    
                </div>
                
                <!-- 航班头部布局 -->
                <FlightsListHead/>
                
                <!-- 航班信息 -->
                <FlightsItem v-for="(item, index) in dataList"
                :key="index"
                :data="item"/>

                <!-- size-change: 切换条数时候触发的事件 -->
                <!-- current-change：切换页数时候触发的事件 -->
                <!-- current-page：当前的页数 -->
                <!-- page-size: 当前的条数 -->
                <!-- total: 总条数 -->
                <el-pagination
                    @size-change="handleSizeChange"
                    @current-change="handleCurrentChange"
                    :current-page="pageIndex"
                    :page-sizes="[5, 10, 15, 20]"
                    :page-size="pageSize"
                    layout="total, sizes, prev, pager, next, jumper"
                    :total="total">
                </el-pagination>
            </div>

            <!-- 侧边栏 -->
            <div class="aside">
                <!-- 侧边栏组件 -->
            </div>
        </el-row>
    </section>
</template>

<script>
// 航班列表头部组件
import FlightsListHead from "@/components/air/flightsListHead.vue"
// 机票航班列表
import FlightsItem from "@/components/air/flightsItem.vue"

export default {
    data(){
        return {
            // 总数据, 里面包含了info,flights,total,options属性
            flightsData: {},
            // 这个属性专门用来存放切割出来的数组
            dataList: [],
            // 当前的页数
            pageIndex: 1,
            // 当前显示的条数
            pageSize: 5,
            // 总条数
            total: 0
        }
    },
    components: {
        FlightsListHead,
        FlightsItem
    },
    mounted(){
        // 请求机票列表
        this.$axios({
            url: "/airs",
            params: this.$route.query
        }).then(res => {
            // 总的数据，里面包含了info,flights,total,options属性
            this.flightsData = res.data
            // 请求完成后切割出第一页的数据
            this.dataList = this.flightsData.flights.slice(0, this.pageSize);
            // 总条数
            this.total = this.flightsData.total;
        })
    },
    methods: {
        // 切换条数时候触发的事件
        handleSizeChange(val){
            // 显示条数
            this.pageSize = val;
            // 一般条数发生了变化会回到第一页
            this.pageIndex = 1;
            // 重新切割数组
            this.dataList = this.flightsData.flights.slice(
                (this.pageIndex - 1) * this.pageSize, 
                this.pageIndex * this.pageSize
            );
        },
        // 切换页数时候触发的事件
        handleCurrentChange(val){
            // 修改页数
            this.pageIndex = val;
            // 重新切割数组
            this.dataList = this.flightsData.flights.slice(
                (this.pageIndex - 1) * this.pageSize, 
                this.pageIndex * this.pageSize
            );
        }
    }
}
</script>

<style scoped lang="less">
    .contianer{
        width:1000px;
        margin:20px auto;
    }

    .flights-content{
        width:745px;
        font-size:14px;
    }

    .aside{
        width:240px;
    } 
</style>