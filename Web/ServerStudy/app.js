const Koa = require('koa')
const app = new Koa()
const views = require('koa-views')
const json = require('koa-json')
const onerror = require('koa-onerror')
const bodyparser = require('koa-bodyparser')
const logger = require('koa-logger')
const cors = require('koa2-cors')                      // 解决跨域问题
const {db} = require('./config/db')                    // 数据库初始化


const index = require('./routes/index')
const users = require('./routes/users')
const student = require('./routes/student')

// error handler
onerror(app)

// middlewares

// 解决跨域问题
app.use(cors())
// 加入解析post请求中body的中间件
app.use(bodyparser({
  enableTypes:['json', 'form', 'text']
}))
// 加入解析json的中间件
app.use(json())
// 加入log记录的中间件
app.use(logger())
// 设置静态资源目录
app.use(require('koa-static')(__dirname + '/public'))

// 设置views的目录和所使用的模板
app.use(views(__dirname + '/views', {
  extension: 'pug'
}))

// logger
app.use(async (ctx, next) => {
  const start = new Date()
  await next()
  const ms = new Date() - start
  console.log(`${ctx.method} ${ctx.url} - ${ms}ms`)
})

// routes
// 加载路由
app.use(index.routes(), index.allowedMethods())
app.use(users.routes(), users.allowedMethods())
app.use(student.routes(), student.allowedMethods())

// 连接数据库
;(async ()=>{
  await db()
})()

// error-handling
// 监听错误
app.on('error', (err, ctx) => {
  console.error('server error', err, ctx)
});

module.exports = app
