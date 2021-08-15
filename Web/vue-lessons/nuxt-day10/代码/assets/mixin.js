// 把可以复用的数据提取出来到这个单独的文件，然后哪个组件需要用到下面这些属性，就混入进去
export default {
    data(){
        return {
            message: "hello"
        }
    }
}