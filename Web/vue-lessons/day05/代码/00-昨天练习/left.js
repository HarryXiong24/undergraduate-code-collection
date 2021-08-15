// 这里面的所有内容都可以改，只要实现功能
var left = {
    // 组件内的data必须使用函数
    data(){
        return {
            // 商品列表
            goods: [
                { title: "iphone 11", price: 10000 },
                { title: "iphone 8", price: 8008 },
                { title: "iphone 6", price: 6000 },
            ]
        }
    },
    methods: {
        // 点击加入购物车按钮时候触发的事件
        // item就是商品对象
        handeClick(item){
            // 把当前点击的商品传递给父组件
            this.$emit('getgoods', item)
        },
    },
    template: `
        <div class="left">
            <div v-for="(item, index) in goods">
                <p>标题：{{ item.title }}</p>
                <p>价格：{{ item.price }}</p>
                <button @click="handeClick(item)">加入购物车</button>
            </div>
        </div>
    `
}