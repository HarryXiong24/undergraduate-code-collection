const Koa = require('koa')
const app = new Koa()
const { connect , initSchemas } = require('./database/init.js')
const mongoose = require('mongoose')
const bodyParser = require('koa-bodyparser')   // 后台接受post数据
const cors = require('koa2-cors')   // 支持跨域
const Router = require('koa-router')

app.use(bodyParser())
app.use(cors())

// 引入路由
let user = require('./appApi/user.js')
let home = require('./appApi/home.js')
let goods = require('./appApi/goods.js')

// 装载所有子路由
let router = new Router()
// ''指前缀必须为/user，之后接路由里的路径
router.use('/user',user.routes())
router.use('/home',home.routes())
router.use('/goods',goods.routes())
//egg.js


// 加载路由中间件
app.use(router.routes())
app.use(router.allowedMethods())


;(async ()=>{
    await connect()
    initSchemas()
})()


app.use(async(ctx)=>{
    ctx.body='<h1>Hello Koa2</h1>'
})

// 监听窗口
app.listen(3000,()=>{
    console.log('[Server] starting at port 3000')
})