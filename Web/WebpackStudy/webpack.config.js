// webpack.config.js

// node内置核心模块，用来处理路径问题。
let path = require('path')
let HTMLWebpackPlugin = require('html-webpack-plugin')

// 开始配置
module.exports = {
  /**
   * mode是打包后的模式，默认有两种，production和development
   * production模式会压缩代码，是生产环境后打包的
   * 而development不会压缩代码，便于开发者观察打包后的结果
   */
  mode: 'development', // 这个模式只对压缩的js文件有效

  entry: './src/index.js', // 打包程序的入口
  output: {
    filename: 'main.js', // 打包后的文件名
    /**
     * filename: 'main.[hash].js'，生成hash文件名，写成这种方式可以防止覆盖和缓存，每次生成的文件都不一样
     * filename: 'main.[hash:8].js'// 生成8位的hash文件名
     */

    path: path.resolve(__dirname, 'dist')
    /**
     * 打包后的路径，注意，该路径必须是绝对路径
     * path.resolve方法会将生成的文件路径拼接成一个绝对路径，该路径默认是以整个系统盘为路径的
     * 可以在前面加一个__dirname参数改变成以当前根目录为绝对路径
     */
  },

  // 开发服务器的配置
  devServer: {
    port: 3000, // 改变开启的端口号
    progress: true, // 开启内存打包中的进度条，这样我们能清楚地看到打包的进程
    open: true, // 自动打开浏览器
    contentBase: './build',
    /**
     * 内存打包指向的目录
     * 开启服务器指向的入口打包文件的地址
     * 默认是index.html文件，到目前需要自己创建该html文件和引入对应打包后的js文件，之后会有自动创建
     */

    compress: true //压缩
  },

  // plugins是一个数组，放着所有的webpack插件，注意是从下到上，如果有关联项需要考虑位置
  plugins: [
    new HTMLWebpackPlugin({
      template: './src/index.html', // html模板，会去找到这个模板
      filename: 'index.html', // 打包后的文件名，默认不写也是index.html
      // 对打包的html模板进行压缩
      minify: {
        removeAttributeQuotes: true, // 删除属性的双引号，除了一些特殊的删除不了以外都能删除
        collapseWhitespace: true,    // 折叠空行将所有代码变成一行
        removeComments: true         // 移除注释
      },
      hash: true // 给打包后在模板中引入的文件名生成hash戳，防止缓存
    })
  ],

  // 模块配置
  module: {
    // 配置规则
    rules: [
      /**
       * css-loader解析css中的语法，如@import这种
       * style-loader用于把css插入到模板html的head标签中
       * 至于为什么要两个，是因为loader的能力尽量要求单一
       */
      {
        // 匹配css结尾的文件
        test: /\.css$/,
        use: [
          {
            // 创建style标签，将js的样式资源插入进行，添加到head中生效
            loader: 'style-loader',
            options: {
              // 改变样式插入的位置为head标签的顶部
              insertAt: 'top'
            }
          },
          // 将css变成commonjs模块加入到js中，里面的内容是字符串
          'css-loader' // 主要解析@import这种路径
        ]
      },
      // 可以解析less文件
      {
        test: /\.less$/,
        use: [
          {
            loader: 'style-loader',
            options: {
              // 改变样式插入的位置为head标签的顶部
              insertAt: 'top'
            }
          },
          'css-loader', // 主要解析@import这种路径
          'less-loader' // 主要把less转换为css
        ]
      },
      // 可以解析scss文件
      {
        test: /\.scss$/,
        use: [
          {
            loader: 'style-loader',
            options: {
              // 改变样式插入的位置为head标签的顶部
              insertAt: 'top'
            }
          },
          'css-loader', // 主要解析@import这种路径
          'scss-loader' // 主要把less转换为css
        ]
      }
    ]
  },

}