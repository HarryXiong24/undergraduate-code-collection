<template>
    <div class="filters">
        <el-row type="flex" class="filters-top" justify="space-between" align="middle">
            <el-col :span="8">
                单程： 
                {{data.info.departCity}} - {{data.info.destCity}}
                / 
                {{data.info.departDate}}
            </el-col>

            <el-col :span="4">
                <el-select size="mini" v-model="airport" placeholder="起飞机场">
                    <el-option
                    v-for="(item, index) in data.options.airport"
                    :key="index"
                    :label="item"
                    :value="item"
                    >
                    </el-option>
                </el-select>
            </el-col>

            <el-col :span="4">
                <el-select size="mini" v-model="flightTimes"  placeholder="起飞时间">
                    <!-- option的value不能放对象类型包括数组，但是需要知道当前 
                    选中的是哪个时间段，所以就在value属性中拼接了一个字符串 -->
                    <el-option
                    v-for="(item, index) in data.options.flightTimes"
                    :key="index"
                    :label="`${item.from}:00 - ${item.to}:00`"
                    :value="`${item.from},${item.to}`"
                    >
                    </el-option>
                </el-select>
            </el-col>
            <el-col :span="4">
                <el-select size="mini" v-model="company" placeholder="航空公司">
                    <el-option
                    v-for="(item, index) in data.options.company"
                    :key="index"
                    :label="item"
                    :value="item">
                    </el-option>
                </el-select>
            </el-col>
            <el-col :span="4">
                <el-select size="mini" v-model="airSize" placeholder="机型">
                    <el-option
                    v-for="(item, index) in airSizeList"
                    :key="index"
                    :label="item.label"
                    :value="item.value">
                    </el-option>
                </el-select>
            </el-col>
        </el-row>
        <div class="filter-cancel">
            筛选：
            <el-button 
                       type="primary" 
                       round 
                       plain 
                       size="mini" 
                       @click="handleFiltersCancel">
                撤销
    		</el-button>
        </div>
        <!-- 只是单纯的为了能够出发computed的filter函数的运行，并不需要渲染 -->
        <div v-show="false">{{filter}}</div>
    </div>
</template>

<script>
export default {
    data(){
        return {
            airport: "",        // 机场
            flightTimes: "",    // 出发时间
            company: "",        // 航空公司
            airSize: "",        // 机型大小

            // 自己声明一个飞机的大小类型的数组
            airSizeList: [
                { label: "大", value: "L" },
                { label: "中", value: "M" },
                { label: "小", value: "S" }
            ]
        }
    },
    props: {
        // 由父组件传递过来的总数据(包含了info,flights,total,options)
        data: {
            type: Object,
            default: {}
        }
    },
    computed: {
        // computed的属性如果没有应用函数是不会执行的
        filter(){
            // 其他写法：自己思考，看不懂也无所谓
            // const filters = [
            //     { key: "airline_name", value: this.company },
            //     { key: "plane_size", value: this.airSize }
            // ]

            // // 过滤有值的条件加入到筛选
            // const hasFilters = filters.filter(v => { return v.value });

            // const arr = this.data.flights.filter(v => {
            //     const valid = hasFilters.every(item => {
            //         return v[item.key] === item.value;
            //     })
            //     return valid;
            // })

            // this.$emit("getData", arr);

            // 第一种写法（推荐）
            const arr = this.data.flights.filter(v => {
                // 先默认所有的航班都是符合条件的
                let valid = true;

                // 当条件（this.company）有值的时候我们才需要判断，表示用户选择了条件
                // 由于valid变量已经假设所有的数据都是符合条件的
                // 所以是不符合条件的条件的航班，就把valid设置为false，最后就return出false
                // 自然这条数据就不会加入到arr中
                if(this.company && v.airline_name !== this.company){
                    valid = false;
                }

                // 起飞机场
                if(this.airport && v.org_airport_name !== this.airport){
                    valid = false;
                }

                // 起飞时间
                if(this.flightTimes){
                    // 假设 this.flightTimes等于 6,12
                    const time = this.flightTimes.split(","); // [6, 12]
                    // 每个航班的出发时间的小时
                    const current = v.dep_time.split(":")[0];
                    if(+time[0] > +current || +current >= +time[1]){
                        valid = false;
                    }
                }

                // 机型大小
                if(this.airSize && v.plane_size !== this.airSize){
                    valid = false;
                }

                // valid是true会把当前这条数据加入到新数组，如果是false就不加
                return valid;
            })

            // 触发父组件传递过来的事件，主要功能是把航班数组传递回去给父组件
            this.$emit("getData", arr);
            
            return "";
        }
    },
    methods: {
        // 撤销条件时候触发
        handleFiltersCancel(){
            // 清空搜索的条件
            this.airport = "";
            this.flightTimes = "";
            this.company = "";
            this.airSize = "";
        },
    }
}
</script>

<style scoped lang="less">
    .filters{
        margin-bottom:20px;
    }

    .filters-top{
        > div{
            /deep/ .el-select{
                margin-left:10px;
            }
        }
    }

    .filter-cancel{
        margin-top:10px;
    }
</style>