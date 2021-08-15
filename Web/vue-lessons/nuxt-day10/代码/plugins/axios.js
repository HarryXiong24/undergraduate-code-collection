import { Message } from 'element-ui';
// plugins的所有文件都会导入到项目中，并且是全局的，
// 类似于在普通的vue项目中的main.js里面的内容，对整个项目都有效

// 1.拦截axios的错误, 插件必须要要暴露出一个函数
export default (nuxt) => {
    // 2.onError在axions请求错误的时候会触发，err是错误的对象
    nuxt.$axios.onError(err => {
        // err.response是错误对象的详细信息
        const {statusCode, message} = err.response.data;

        if(statusCode === 400){
            Message.error(message)
        }

        // 说明当前没有登录
        if(statusCode === 403 || statusCode === 401){
            Message.error("当前没有登录");
            // 跳转到登录页
            nuxt.redirect("/user/login");
        }
    })
}   
