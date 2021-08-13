/**
 * 获取图片数量，确定ul的宽度
 */
var ul = document.getElementById("picture");
var li = ul.getElementsByTagName("li");
ul.style.width = 780 * li.length + "px";

/**
 * 获取链接数量，确定连接的位置
 */
var div = document.getElementById("nav");
var a = div.getElementsByTagName("a");
div.style.left = (780 - (13 * a.length + 4 * (a.length + 1))) / 2 + "px";

var index = 0;
setA();
autoChange();

/**
 * 点击链接图标进行切换
 */
for(var i = 0; i < a.length; i++){
    a[i].num = i;
    a[i].onclick = function(){
        index = this.num;
        move(ul, "left", -780*index, -10000, function(){});
        setA();
    }
}

function getStyle(obj , name){
        
    if(window.getComputedStyle){
        //正常浏览器的方式，具有getComputedStyle()方法
        return getComputedStyle(obj , null)[name];
    }else{
        //IE8的方式，没有getComputedStyle()方法
        return obj.currentStyle[name];
    }       
}

function move(obj, attr, target, speed, callback){
    clearInterval(obj.timer);

    obj.timer = setInterval(function(){
        var oldValue = parseInt(getStyle(obj, attr));
        var newValue = oldValue + speed;

        if(newValue < target){
            newValue = target;
        }

        obj.style[attr] = newValue + "px";

        if(newValue == target){
            clearInterval(obj.timer);
            callback();
        }

    }, 20);
}

/**
 * 设置链接的点击颜色
 */
function setA(){
    if(index >= li.length - 1){
        index = 0;
        ul.style.left = 0;
    }

    for(var i = 0; i < a.length; i++){
        a[i].style.backgroundColor = "";
    }

    a[index].style.backgroundColor = "brown";
}

var timer;
function autoChange(){
    clearInterval(timer);
    timer = setInterval(function(){
        index++;
        index = index % li.length;
        move(ul, "left", -780*index, -20, function(){
            setA();
        });
    }, 3000);
}
