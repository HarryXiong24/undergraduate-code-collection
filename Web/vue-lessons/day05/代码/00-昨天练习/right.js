var right = {
    // 声明组件可以接收什么属性
    props: ['cartgoods'],
    template: `
        <div class="right">
            <div v-for="(item, index) in cartgoods">
                <p>标题：{{ item.title }}</p>
                <p>价格：{{ item.price }}</p>
            </div>
        </div>
    `
}