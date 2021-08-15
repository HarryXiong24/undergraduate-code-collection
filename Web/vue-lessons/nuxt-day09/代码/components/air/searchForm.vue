<template>
    <div class="search-form">
        <!-- 头部tab切换 -->
        <el-row type="flex" class="search-tab">
            <span
                v-for="(item, index) in tabs"
                :key="index"
                @click="handleSearchTab(item, index)"
                :class="{active: index === currentTab}"
            >
                <i :class="item.icon"></i>
                {{item.name}}
            </span>
        </el-row>

        <!-- 机票搜索的表单 -->
        <el-form class="search-form-content" 
        :model="form" 
        :rules="rules" 
        ref="form" 
        label-width="80px">
            <!-- 出发城市的输入框 -->
            <el-form-item label="出发城市" prop="departCity">
                <!-- fetch-suggestions：获取搜索建议，它的功能就是根据当前输入的关键字，发起请求，把请求的结果显示下拉列表中 -->
                <!-- fetch-suggestions比较类似input事件，有监听作用，不过他可以把数据展示在下拉列表 -->
                <!-- @select: 选中下拉列表某一项的时候触发的事件，通过参数获取到当前选中的那个选项 -->
                <el-autocomplete
                    :fetch-suggestions="queryDepartSearch"
                    placeholder="请搜索出发城市"
                    @select="handleDepartSelect"
                    class="el-autocomplete"
                    v-model="form.departCity"
                    @blur="handlDepartBlur"
                ></el-autocomplete>
            </el-form-item>

            <!-- 到达城市的输入框 -->
            <el-form-item label="到达城市" prop="destCity">
                <el-autocomplete
                    :fetch-suggestions="queryDestSearch"
                    placeholder="请搜索到达城市"
                    @select="handleDestSelect"
                    class="el-autocomplete"
                    v-model="form.destCity"
                    @blur="handlDestBlur"
                ></el-autocomplete>
            </el-form-item>
            
            <!-- 出发时间 -->
            <el-form-item label="出发时间" prop="departDate">
                <!-- change 用户确认选择日期时触发 -->
                <!-- value-format 设置时间的格式 -->
                <el-date-picker
                    type="date"
                    placeholder="请选择日期"
                    style="width: 100%;"
                    @change="handleDate"
                    v-model="form.departDate"
                    value-format="yyyy-MM-dd"
                    :picker-options="pickerOptions"
                ></el-date-picker>
            </el-form-item>

            <el-form-item label>
                <el-button
                    style="width:100%;"
                    type="primary"
                    icon="el-icon-search"
                    @click="handleSubmit"
                >搜索</el-button>
            </el-form-item>
            <div class="reverse">
                <span @click="handleReverse">换</span>
            </div>
        </el-form>
    </div>
</template>

<script>
export default {
    data() {
        return {
            tabs: [
                { icon: "iconfont icondancheng", name: "单程" },
                { icon: "iconfont iconshuangxiang", name: "往返" }
            ],
            currentTab: 0,
            // 表单的数据
            form: {
                departCity: "", // 出发城市
                departCode: "", // 出发城市的字母代码
                destCity:"", //到达城市
                destCode: "", // 到达城市的字母代码
                departDate: "" // 出发日期
            },

            // 出发城市的下拉列表数据
            departCities: [],
            // 出发城市的下拉列表数据
            destCities: [],
            // 日期禁用选项
            pickerOptions: {
                disabledDate(time) {
                    return time.getTime() < Date.now() - 3600 * 1000 * 24;
                }
            },
            // 表单的校验规则,trigger是随便填的，默认是blur，主要是blur交互我们觉得不好看，想覆盖掉这个功能
            rules: {
                departCity: [
                    { required: true, message: "请选中出发城市", trigger: "abc" }
                ],
                destCity: [
                    { required: true, message: "请选中到达城市", trigger: "abc"  }
                ],
                departDate: [
                    { required: true, message: "请选中出发时间", trigger: "abc"  }
                ]
            }
        };
    },
    methods: {
        // 封装请求城市的方法
        getCities(value){
            // 请求和value相关的城市
            return this.$axios({
                url: "/airs/city",
                params: {
                    name: value
                }
            }).then(res => {
                // data是城市的数组
                const {data} = res.data;
                // data的属性没有value属性，需要转换下
                const newData = data.map(v => {
                    v.value = v.name.replace("市", "");
                    return v;
                })
                
                return newData;
            })
        },

        // tab切换时触发
        handleSearchTab(item, index) {
            // 如果点击的是往返的按钮
            if(index === 1){
                // 提示当前暂不支持往返机票
                this.$alert('当前暂不支持往返机票', '提示', {
                    confirmButtonText: '确定'
                });
            }
        },

        // 监听出发城市输入框的变化，一旦输入框的值发生了变化就会触发该事件
        // value是输入框的值，cb是函数必须要调用
        // cb接收的参数有个固定的格式，参数必须是一个数组，并且数组是由对象组成的，还有对象必须要有value属性
        queryDepartSearch(value, cb) {  
            
            // 如果value值空的，就不需要请求
            if(!value){
                // 禁止输入框的值是空的时候显示下拉框
                cb([]);
                // 如果输入框的值是空的话把之前的城市列表删除掉
                this.departCities = [];
                return;
            }

            // 监听输入框有值的时候重新验证表单，可以消除掉红的报错信息
            this.$refs.form.validateField("departCity");

            // 根据value请求城市
            this.getCities(value).then(newData => {
                // 保存到data中，给blur事件使用, 失去焦点时候选中第一个
                this.departCities = newData;
                // cb是要请求成功之后才调用，因为在这里才可以拿到城市的数据
                cb(newData);
            })
        },

        // 出发城市失去焦点时候默认选中第一个
        handlDepartBlur(){
            if(this.departCities.length > 0){
                this.form.departCity = this.departCities[0].value;
                this.form.departCode = this.departCities[0].sort;
            }
        },

        // 目标城市输入框获得焦点时触发
        // value 是选中的值，cb是回调函数，接收要展示的列表
        queryDestSearch(value, cb) {
            // // 如果value值空的，就不需要请求
            if(!value){
                // 禁止输入框的值是空的时候显示下拉框
                cb([]);
                // 如果输入框的值是空的话把之前的城市列表删除掉
                this.destCities = [];
                return;
            }

            // 监听输入框有值的时候重新验证表单，可以消除掉红的报错信息
            this.$refs.form.validateField("destCity");

            // 根据value请求城市
            this.getCities(value).then(newData => {
                // 保存到data中，给blur事件使用, 失去焦点时候选中第一个
                this.destCities = newData;
                // cb是要请求成功之后才调用，因为在这里才可以拿到城市的数据
                cb(newData);
            })
        },

        // 出发城市失去焦点时候默认选中第一个
        handlDestBlur(){
            if(this.destCities.length > 0){
                this.form.destCity = this.destCities[0].value;
                this.form.destCode = this.destCities[0].sort;
            }
        },

        // 出发城市下拉选择时触发
        handleDepartSelect(item) {
            this.form.departCode = item.sort;
        },

        // 目标城市下拉选择时触发
        handleDestSelect(item) {
            this.form.destCode = item.sort;
        },

        // 确认选择日期时触发
        handleDate(value) {},

        // 触发和目标城市切换时触发
        handleReverse() {
            const {departCity, departCode, destCity, destCode} = this.form;
            // 交叉赋值
            this.form.destCity = departCity;
            this.form.destCode = departCode;

            this.form.departCity = destCity;
            this.form.departCode = destCode;
        },

        // 提交表单是触发
        handleSubmit() {
            // 表单验证
            this.$refs.form.validate(valid => {
                if(valid){
                    // 保存this.form数据到vuex
                    this.$store.commit("air/setSearchList", this.form);

                    // 路由跳转，path指定的路径，query属性指定的问号后面的参数
                    // 如果是动态参数就使用params
                    this.$router.push({
                        path: "/air/flights",
                        query: this.form
                    })
                }
            })
        }
    },
    mounted() {}
};
</script>

<style scoped lang="less">
.search-form {
    border: 1px #ddd solid;
    border-top: none;
    width: 360px;
    height: 350px;
    box-sizing: border-box;
}

.search-tab {
    span {
        display: block;
        flex: 1;
        text-align: center;
        height: 48px;
        line-height: 42px;
        box-sizing: border-box;
        border-top: 3px #eee solid;
        background: #eee;
    }

    .active {
        border-top-color: orange;
        background: #fff;
    }

    i {
        margin-right: 5px;
        font-size: 18px;

        &:first-child {
            font-size: 16px;
        }
    }
}

.search-form-content {
    padding: 15px 50px 15px 15px;
    position: relative;

    .el-autocomplete {
        width: 100%;
    }
}

.reverse {
    position: absolute;
    top: 35px;
    right: 15px;

    &:after,
    &:before {
        display: block;
        content: "";
        position: absolute;
        left: -35px;
        width: 25px;
        height: 1px;
        background: #ccc;
    }

    &:after {
        top: 0;
    }

    &:before {
        top: 60px;
    }

    span {
        display: block;
        position: absolute;
        top: 20px;
        right: 0;
        font-size: 12px;
        background: #999;
        color: #fff;
        width: 20px;
        height: 20px;
        line-height: 18px;
        text-align: center;
        border-radius: 2px;
        cursor: pointer;

        &:after,
        &:before {
            display: block;
            content: "";
            position: absolute;
            left: 10px;
            width: 1px;
            height: 20px;
            background: #ccc;
        }

        &:after {
            top: -20px;
        }

        &:before {
            top: 20px;
        }
    }
}
</style>
