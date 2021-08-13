const Koa = require('koa')
const Router = require('koa-router')

// 实例化
const app = new Koa()
const router = new Router()

// 应用级中间件
app.use(async (ctx, next) => {
  console.log(new Date())    // 运行后在匹配任何一个路由之前都会先执行一下这个中间件
  await next()               // 当前路由匹配完成后继续向下匹配
})

// 错误处理中间件
app.use(async (ctx, next)=> {
  console.log('这是一个中间件')
  next();
  console.log(ctx.status)
  if(ctx.status==404){
    ctx.status = 404;
    ctx.body="这是一个 404 页面"
  }
})

// 配置路由
router.get('/', async (ctx, next) => {     // ctx是context，包含request和response
  ctx.body='Start'
})

// 获取get传值
// 在 koa2 中 GET 传值通过 request 接收，但是接收的方法有两种：query 和 querystring
// query：返回的是格式化好的参数对象，querystring：返回的是请求字符串
// 例url：/news?name=xhw&id=2
router.get('/news', async (ctx, next) => { 
  // 从上下文中直接获取
  console.log(ctx.query)        // { name: 'xhw', id: '2' }
  console.log(ctx.querystring)  // name=xhw&id=2
  console.log(ctx.url)          // /news?name=xhw&id=2

  // 从request中获取GET请求
  console.log(ctx.request)                // request里的所有信息
  console.log(ctx.request.query)          // { name: 'xhw', id: '2' }
  console.log(ctx.request.querystring)    // name=xhw&id=2
 
})

// 动态路由，动态路由可以多个值
router.get('/news/:aid/:cid', async (ctx, next) => {
  console.log(ctx.params); // { aid: '123' } 获取动态路由的数据
  ctx.body='这是新闻页面'
});

// 路由级中间件
// 要求匹配到content路由以后继续往下匹配路由
router.get('/content', async (ctx, next) => {    
  console.log('这是新闻页面');
  await next()                   // 如果没有这个next那么访问路由/content会找不到这个路由
})
router.get('/content', async (ctx) => {
  ctx.body='这是content页面'
});

// 启动路由
app
  .use(router.routes())   // 启动路由
  .use(router.allowedMethods());  // 出错了或者没有设置响应头会自动配置，可以选择是否配置

// 监听端口
app.listen(8081);