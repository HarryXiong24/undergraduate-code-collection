const router = require('koa-router')()
const student = require('../models/student')

// 设置了一个路由前缀
router.prefix('/student')

router.get('/', (ctx, next) => {
  var temp;
  // 向数据库中插入一个文档
  // StuModel.create(doc, function(err){});
  student.create({
    name:"白骨精",
    age:16,
    address:"白骨洞"
  }, function (err) {
    if(!err){
      
    }
  });

  ctx.body = 'ok'
})

router.get('/find', async (ctx, next) => {
  var temp;
  await student.findOne({name:"白骨精"}, function (err , docs) {
    if(!err){
      temp = docs
    }
  });
  ctx.body = temp
})

module.exports = router
