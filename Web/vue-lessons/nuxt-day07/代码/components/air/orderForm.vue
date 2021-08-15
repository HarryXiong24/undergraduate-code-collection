<template>
    <div class="main">
        <div class="air-column">
            <h2>乘机人</h2>
            <el-form class="member-info">
                <!-- 乘机人用户列表，根据form.users要循环 -->
                <div class="member-info-item" 
                v-for="(item, index) in form.users" 
                :key="index">

                    <el-form-item label="乘机人类型">
                        <!-- 重点关注input,忽略select即可 -->
                        <el-input 
                        placeholder="姓名" 
                        class="input-with-select" 
                        v-model="item.username">
                            <el-select 
                            slot="prepend" 
                            value="1" 
                            placeholder="请选择">
                                <el-option label="成人" value="1"></el-option>
                            </el-select>
                        </el-input>
                    </el-form-item>

                    <el-form-item label="证件类型">
                        <!-- 重点关注input,忽略select即可 -->
                        <el-input 
                        placeholder="证件号码"  
                        class="input-with-select" 
                        v-model="item.id">
                            <el-select 
                            slot="prepend" 
                            value="1"           
                            placeholder="请选择">
                                <el-option label="身份证" value="1" :checked="true"></el-option>
                            </el-select>
                        </el-input>
                    </el-form-item>
                    <!-- 删除用户 -->
                    <span class="delete-user" @click="handleDeleteUser(index)">-</span>
                </div>
            </el-form>

            <el-button class="add-member" type='primary' @click="handleAddUsers">添加乘机人</el-button>
        </div>

        <div class="air-column">
            <h2>保险</h2>
            <div>
                <!-- 数据来自于后台，循环渲染保险的列表数据 -->
                <div class="insurance-item" 
                v-for="(item, index) in detail.insurances"
                :key="index">
                    <!-- change事件在点击时候触发，重点在事件里面获取到id -->
                    <el-checkbox 
                    :checked="false"
                    @change="handleInsurances(item.id)"
                    :label="`${item.type}：￥${item.price}/份×1  最高赔付${item.compensation}`" 
                    border>
                    </el-checkbox> 
                </div>
            </div>
        </div>

        <div class="air-column">
            <h2>联系人</h2>
            <div class="contact">
                <el-form label-width="60px">
                    <el-form-item label="姓名">
                        <!-- 联系人的姓名 -->
                        <el-input v-model="form.contactName"></el-input>
                    </el-form-item>

                    <el-form-item label="手机">
                        <!-- 手机号码 -->
                        <el-input placeholder="请输入内容" v-model="form.contactPhone">
                            <template slot="append">
                            <el-button @click="handleSendCaptcha">发送验证码</el-button>
                            </template>
                        </el-input>
                    </el-form-item>

                    <el-form-item label="验证码">
                        <!-- 手机验证码 -->
                        <el-input v-model="form.captcha"></el-input>
                    </el-form-item>
                </el-form>   
                <el-button type="warning" class="submit" @click="handleSubmit">提交订单</el-button>
            </div>
        </div>
    </div>
</template>

<script>
export default {
    data(){
        return {
            form: {
                users: [
                    { username: "", id: "" },
                ],                  // 乘机人
                insurances: [],     // 选中的保险id
                contactName: "",    // 联系人名字
                contactPhone: "",   // 联系人电话
                captcha: "",        // 验证码这个参数接口文档漏掉了

                invoice: false, // 默认不需要发票
                seat_xid: "",       // 座位id    
                air: "",            // 航班id
            },
            // 机票的详细信息
            detail: {}
        }
    },
    mounted(){
        // 获取问号的参数
        const {id, seat_xid} = this.$route.query;
        // 把航班id和座位赋值给表单
        this.form.air = id;
        this.form.seat_xid = seat_xid;

        // 根据航班的id和座位id请求当前机票的详细
        this.$axios({
            url: "/airs/" + id,
            // get类型请求的参数用params
            params: {
                seat_xid
            }
        }).then(res => {
            // 把机票的信息保存到data,里面有保险和右侧栏需要展示的数据
            this.detail = res.data;
        })
    },
    methods: {
        // 添加乘机人
        handleAddUsers(){
            // 添加多一个乘机人
            this.form.users.push({
                username: "",
                id: ""
            })
        },
        
        // 移除乘机人
        handleDeleteUser(index){
            // 根据点击的index移除乘机人
            this.form.users.splice(index, 1);
        },
        
        // 发送手机验证码
        handleSendCaptcha(){
            if(this.form.contactPhone){
                // 调用user里面actions的方法来发送手机验证码
                this.$store.dispatch("user/sendCaptcha", this.form.contactPhone).then(code => {
                    this.$message.success("验证码发送成功，模拟的验证码是:" + code);
                })
            }else{
                alert("手机号码不能为空")
            }
        },

        // 点击保险的checkbox时候触发
        handleInsurances(id){
            // 判断数组中是否已经包含了该id
            // 如果index大于-1就表示有id，反之就没有
            const index = this.form.insurances.indexOf(id);
            
            if(index > -1){
                // 有该id就删除
                this.form.insurances.splice(index, 1);
            }else{
                // 还没有该id
                this.form.insurances.push(id)
            }
        },

        // 提交订单
        handleSubmit(){
            // 验证先跳过，下次再说

            // 创建订单
            this.$axios({
                url: "/airorders",
                method: "POST",
                headers: {
                    // 这里千万要注意Bearer 后面必须要有一个空格（基于JWT标准）
                    Authorization: `Bearer ` + this.$store.state.user.userInfo.token
                },
                data: this.form
            }).then(res => {
                this.$message.success("订单提交成功")
            })
        }
    }
}
</script>

<style scoped lang="less">
    .air-column{
        border-bottom:1px #ddd dashed;
        padding-bottom: 20px;   
        margin-bottom: 20px;
    }

    .air-column h2{
        margin-bottom: 20px;
        font-size: 22px;
        font-weight: normal;
    }

    /deep/ .el-select .el-input {
        width: 130px;
    }

    .input-with-select{
        width:590px;
    }

    .input-with-select /deep/  .el-input-group__prepend {
        background-color: #fff;
    }
    .member-info /deep/ .el-form-item{
        margin-bottom:0;
    }

    .member-info-item{
        border-bottom:1px #eee dashed;
        padding-bottom: 20px;
        position: relative;

        &:first-child{
            .delete-user{
                display: none;
            }
        }
    }

    .add-member{
        margin-top:20px;
    }

    .delete-user{
        display: block;
        background:#ddd;
        width:16px;
        height:16px;
        font-size:14px;
        text-align: center;
        line-height: 16px;
        color:#fff;
        cursor: pointer;
        border-radius: 50px;
        position:absolute;
        right:-30px;
        top:50%;
    }

    .insurance{
        > div{
            margin-top:10px;
        }
    }

    .insurance-item{
        margin-bottom: 20px;
    }

    .contact{
        /deep/ .el-input{
            width:50%;
        }
    }

    .submit{
        margin: 50px auto;
        display: block;
        width:250px;
        height:50px;
    }
</style>