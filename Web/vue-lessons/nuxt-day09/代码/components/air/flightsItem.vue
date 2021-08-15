<template>
    <div class="flight-item">
        <div @click="isShow = !isShow">
            <!-- 显示的机票信息 -->
            <el-row type="flex" align="middle" class="flight-info">
                <el-col :span="6">
                    <!-- 航空公司和航班的编号 -->
                    <span>{{ data.airline_name }} </span> {{data.flight_no}}
                </el-col>
                <el-col :span="12">
                    <el-row type="flex" justify="space-between" class="flight-info-center">
                        <!-- 出发的信息 -->
                        <el-col :span="8" class="flight-airport">
                            <strong>{{ data.dep_time }}</strong>
                            <span>{{ data.org_airport_name }} {{data.org_airport_quay}}</span>
                        </el-col>
                        <!-- 相隔时间 -->
                        <el-col :span="8" class="flight-time">
                            <span>{{rankTime}}</span>
                        </el-col>
                        <!-- 到达的信息 -->
                        <el-col :span="8" class="flight-airport">
                            <strong>{{ data.arr_time }}</strong>
                            <span>{{ data.dst_airport_name }} {{data.dst_airport_quay}}</span>
                        </el-col>
                    </el-row>
                </el-col>
                <!-- 取的最低价格 -->
                <el-col :span="6" class="flight-info-right">
                    ￥<span class="sell-price">{{data.base_price / 2}}</span>起
                </el-col>
            </el-row>
        </div>
        <div class="flight-recommend" v-show="isShow">
            <!-- 隐藏的座位信息列表 -->
            <el-row type="flex" justify="space-between" align="middle">
                <el-col :span="4">低价推荐</el-col>
                <el-col :span="20">
                    <!-- 需要循环显示的座位列表 -->
                    <el-row 
                    type="flex" 
                    justify="space-between" 
                    align="middle" 
                    class="flight-sell"
                    v-for="(item, index) in data.seat_infos"
                    :key="index">
                        <el-col :span="16" class="flight-sell-left">
                            <span>{{item.name}}</span> | {{item.supplierName}}
                        </el-col>
                        <el-col :span="5" class="price">
                            ￥{{item.settle_price}}
                        </el-col>
                        <el-col :span="3" class="choose-button">
                            <!-- 不管是router-link或者nuxt-link都可以使用对象的方式来写跳转的路径和参数 -->
                            <nuxt-link :to="{
                                path: `/air/order`, 
                                query: {
                                    id: data.id,
                                    seat_xid: item.seat_xid
                                } 
                            }">
                                <el-button 
                                type="warning" 
                                size="mini">
                                选定
                                </el-button>
                            </nuxt-link>
                            <p>剩余：{{item.discount}}</p>
                        </el-col>
                    </el-row>
                </el-col>
            </el-row>
        </div>
    </div>
</template>

<script>
export default {
    data(){
        return {
            // 是否显示座位列表
            isShow: false
        }
    },

    // props声明为对象的好处，
    // 1.可以声明类型，避免类型错误（但是不能阻止）
    // 2.如果使用组件时候不传该属性，可以有默认值
    props: {
        // 数据
        data: {
            // 类型
            type: Object,
            // 默认是空对象
            default: {}
        }
    },

    computed: {
        // 相隔时间
        rankTime(){
            // 把到达时间减去出发时间
            const arr = this.data.arr_time // 12.50
            const dep = this.data.dep_time // 10.30

            const end = arr.split(":"); // [12, 50] 字符串
            const start = dep.split(":"); // [10, 30] 字符串
            
            // 如果到达时间的小时小于出发时间的小时，那么就表示到达时间是第二天
            // 必须是飞行时间不能超过24小时，现实生活不存在这个条件
            if(end[0] < start[0]){
                end[0] = +end[0] + 24;
            }

            // 相隔时间,主要要强制转换字符串
            const dis = (end[0] * 60 + +end[1]) - (start[0] * 60 + +start[1]);
            // 小时
            const hours = Math.floor(dis / 60)
            // 分钟
            const min = dis % 60;

            return `${hours}小时${min}分`;
        }
    }
}
</script>

<style scoped lang="less">
    .flight-item{
        border:1px #ddd solid;
        margin-bottom: 10px;

        .flight-info{
            padding:15px;
            cursor: pointer;

            > div{
                &:first-child, &:last-child{
                    text-align: center;
                }
            }
        }

        .flight-info-center{
            padding:0 30px;
            text-align: center;

            .flight-airport{
                strong{
                    display: block;
                    font-size:24px;
                    font-weight: normal;
                }
                span{
                    font-size: 12px;
                    color:#999;
                }
            }

            .flight-time{
                span{
                    display: inline-block;
                    padding:10px 0;
                    border-bottom: 1px #eee solid;
                    color:#999;
                }
            }
        }

        .flight-info-right{
            
            .sell-price{
                font-size: 24px;
                color:orange;
                margin:0 2px;
            }
        }
    }

    .flight-recommend{
        background: #f6f6f6;
        border-top:1px #eee solid;
        padding:0 20px;

        .flight-sell{
            border-bottom:1px #eee solid;
            padding:10px 0;

            &:last-child{
                border-bottom: none;
            }

            .flight-sell-left{
                font-size: 12px;
                span{
                    color:green;
                }
            } 

            .price{
                font-size: 20px;
                color:orange;
            }

            .choose-button{
                text-align: center;
                color:#666;
                button{
                    display: block;
                    width:100%;
                    margin-bottom:5px;
                }
            }
        }
    }
</style>