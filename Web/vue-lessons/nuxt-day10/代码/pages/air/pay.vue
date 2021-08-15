<template>
    <div class="container">
        <div class="main">
            <div class="pay-title">
                <!-- Number().toFixed(2) 保留2位小数点 -->
                支付总金额 <span class="pay-price">￥ {{ Number(detail.price).toFixed(2) }}</span>
            </div>
            <div class="pay-main">
                <h4>微信支付</h4>
                <el-row type="flex" 
                justify="space-between" 
                align="middle"
                class="pay-qrcode">
                    <div class="qrcode">
                        <!-- 二维码 -->
                        <canvas id="qrcode-stage"></canvas>
                        <p>请使用微信扫一扫</p>
                        <p>扫描二维码支付</p>
                    </div>
                    <div class="pay-example">
                        <img src="http://157.122.54.189:9093/images/wx-sweep2.jpg" alt="">
                    </div>
                </el-row>
            </div>
        </div>
    </div>
</template>

<script>
import QRcode from "qrcode"
export default {
    data(){
        return {
            // 订单详细信息
            detail: {},
            // 定时器的对象
            timer: ""
        }
    },
    mounted(){
        // 把setTimeout的函数设置成async函数，函数内部可以使用await来同步执行代码
        setTimeout(async () => {
            // 请求订单订单详情
            // await的返回值就是then的函数的参数（res）,也就是请求成功的结果
            const res = await this.$axios({
                url: "/airorders/" + this.$route.query.id,
                headers: {
                    Authorization: `Bearer ` + this.$store.state.user.userInfo.token
                }
            })
            // 主要使用用到价格和支付链接
            this.detail = res.data;
            // 根据文档调用toCanvas方法来生成二维码
            // 文档地址： https://github.com/soldair/node-qrcode#tocanvascanvaselement-text-options-cberror
            const canvas = document.querySelector("#qrcode-stage");
            // 第一个参数canvas节点元素
            // 第二个是生成二维码的链接
            QRcode.toCanvas(canvas, this.detail.payInfo.code_url, {
                width: 200
            })

            // timer是定时器的对象
            this.timer = setInterval(async () => {
                // 每3秒查询支付状态 
                const checkRes =  await this.$axios({
                    url: "/airorders/checkpay",
                    method: "POST",
                    headers: {
                        Authorization: `Bearer ` + this.$store.state.user.userInfo.token
                    },
                    data: {
                        id: this.detail.id, // 订单id
                        nonce_str: this.detail.price, // 订单金额
                        out_trade_no: this.detail.orderNo
                    }
                })
                // 是否支付成功
                if(checkRes.data.statusTxt == "支付完成"){
                    this.$message.success("订单支付成功");
                    // 停止定时器
                    clearInterval(this.timer);
                    // 跳转到机票首页
                    this.$router.push("/air")
                }
            }, 3000)
        }, 0)
    },

    // 如果组件被卸载或者销毁后（也就是页面切换后），同时也要销毁定时器
    destroyed(){
        // 停止定时器
        clearInterval(this.timer);
    }
}
</script>

<style scoped lang="less">
.container{
    background:#f5f5f5;
    padding: 30px 0;

    .main{
        width:1000px;
        margin:0 auto;

        .pay-title{
            text-align: right;
            span{
                font-size:28px;
                color:orangered;
            }
        }

        .pay-main{
            background:#fff;
            margin-top:10px;
            border-top: 5px orange solid;
            padding:30px;

            h4{
                font-size: 28px;
                font-weight: normal;
                margin-bottom: 10px;
            }

            .pay-qrcode{
                padding:0 80px;
            }

            .qrcode{
                border:1px #ddd solid;
                padding:15px;
                height: fit-content;

                #qrcode-stage{
                    width:200px;
                    height:200px;
                    margin-bottom: 10px;
                }

                p{
                    line-height: 2;
                    text-align: center;
                }
            }
        }
    }
}
</style>