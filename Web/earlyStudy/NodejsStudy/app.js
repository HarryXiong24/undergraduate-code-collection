const Koa = require('koa')
const Router = require('koa-router')
const bodyParser = require('koa-bodyparser')   // 后台接受post数据
const cors = require('koa2-cors')              // 支持跨域

const app = new Koa()
const router = new Router()
app.use(bodyParser())
app.use(cors())

// 引入
let root = require('./router/root.js')
// ''指前缀必须为/user，之后接路由里的路径
router.use('/root', root.routes())

// 使用
app.use(router.routes())
app.use(router.allowedMethods())

// 监听窗口
app.listen(3000, () => {
  console.log('[Server] starting at port 3000')
})