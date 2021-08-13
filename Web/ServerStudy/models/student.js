const mongoose = require('mongoose')

//将mongoose.Schema 赋值给一个变量
var Schema = mongoose.Schema;

//创建Schema（模式）对象
var stuSchema = new Schema({
	name:String,
	age:Number,
	gender:{
		type:String,
		default:"female"  // 设置默认值
	},
	address:String
});

// 发布模型，''里的名字要和表中一模一样
let student = mongoose.model("student" , stuSchema);
module.exports = student