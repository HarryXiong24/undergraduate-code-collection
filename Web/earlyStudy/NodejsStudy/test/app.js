const http = require('http')
const url = require('url')

http.createServer( (req, res) => {
  // console.log(req.url) // 输出url

  // 设置响应头
  // 状态码是200， 文件类型html， 字符集utf-8
  res.writeHead(200, {"Content-type": "text/html; charset=UTF-8 "})

  res.write('this is node.js')

  // console.log(req)

  if (req.url !== '/favicon.ico') {
    // url中的parse方法的使用，解析获取的url

    var userInfo = url.parse(req.url, true).query

    console.log(userInfo)
    console.log(`${userInfo.name} ------ ${userInfo.age}`)
  }

  res.end() // 结束响应

}).listen('8081')