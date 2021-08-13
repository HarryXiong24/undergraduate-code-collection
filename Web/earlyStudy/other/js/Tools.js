/*
 * 参数：
 * 	obj:要执行动画的对象
 * 	attr:要执行动画的样式，比如:left top width height
 * 	target:执行动画的目标位置
 * 	speed:移动的速度，正值，正负函数自己会判断
 *  callback:回调函数，这个函数将会在动画执行完毕以后执行，无则传空函数
 */
function move(obj, attr, target, speed, callback) {
	//关闭上一个定时器
	clearInterval(obj.timer);

	//获取元素目前的位置
	var current = parseInt(getStyle(obj, attr));

	//判断速度的正负值
	if(current > target) {
		//此时速度应为负值
		speed = -speed;
	}

	//开启一个定时器，用来执行动画效果
	//向执行动画的对象中添加一个timer属性，用来保存它自己的定时器的标识
	obj.timer = setInterval(function() {

		//获取box1的原来的left值
		var oldValue = parseInt(getStyle(obj, attr));

		//在旧值的基础上增加
		var newValue = oldValue + speed;

		//判断newValue是否大于800
		//从800 向 0移动
		//向左移动时，需要判断newValue是否小于target
		//向右移动时，需要判断newValue是否大于target
		if((speed < 0 && newValue < target) || (speed > 0 && newValue > target)) {
			newValue = target;
		}

		//将新值设置给box1
		obj.style[attr] = newValue + "px";

		//当元素移动到0px时，使其停止执行动画
		if(newValue == target) {
			//达到目标，关闭定时器
			clearInterval(obj.timer);
			//动画执行完毕，调用回调函数
			callback();
		}

	}, 30);
}


/*
 * 定义一个函数，用来获取指定元素的当前的样式
 * 参数：
 * 		obj 要获取样式的元素
 * 		name 要获取的样式名
 */
function getStyle(obj, name) {

	if(window.getComputedStyle) {
		//正常浏览器的方式，具有getComputedStyle()方法
		return getComputedStyle(obj, null)[name];
	} else {
		//IE8的方式，没有getComputedStyle()方法
		return obj.currentStyle[name];
	}

}

//定义一个函数，用来向一个元素中添加指定的class属性值
/*
 * 参数:
 * 	obj 要添加class属性的元素
 *  classValue 要添加的class值
 * 	
 */
function addClass(obj, classValue) {

	//检查obj中是否含有classValue
	if(!hasClass(obj, classValue)) {
		obj.className += " " + classValue;
	}

}

/*
 * 判断一个元素中是否含有指定的class属性值
 * 	如果有该class，则返回true，没有则返回false
 * 	
 */
function hasClass(obj, classValue) {

	//判断obj中有没有classValue class
	//创建一个正则表达式
	//var reg = /\bb2\b/;
	var reg = new RegExp("\\b" + classValue + "\\b");

	return reg.test(obj.className);

}

/*
 * 删除一个元素中的指定的class属性
 */
function removeClass(obj, classValue) {
	//创建一个正则表达式
	var reg = new RegExp("\\b" + classValue + "\\b");

	//删除class
	obj.className = obj.className.replace(reg, "");

}

/*
 * toggleClass可以用来切换一个类
 * 	如果元素中具有该类，则删除
 * 	如果元素中没有该类，则添加
 */
function toggleClass(obj, classValue) {

	//判断obj中是否含有classValue
	if(hasClass(obj, classValue)) {
		//有，则删除
		removeClass(obj, classValue);
	} else {
		//没有，则添加
		addClass(obj, classValue);
	}
}

/*
* 用来切换菜单折叠和显示状态
*/
function toggleMenu(obj, classValue){
    //在切换类之前，获取元素的高度
    var begin = obj.offsetHeight;
    
    //切换parentDiv的显示
    toggleClass(obj, classValue);
    
    //在切换类之后获取一个高度
    var end = obj.offsetHeight;
    
    //动画效果就是将高度从begin向end过渡
    //将元素的高度重置为begin
    obj.style.height = begin + "px";
    
    //执行动画，从bengin向end过渡
    move(obj,"height",end,10,function(){
        //动画执行完毕，内联样式已经没有存在的意义了，删除即可
        obj.style.height = "";
    });
        
}