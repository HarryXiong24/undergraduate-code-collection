"use strict";
var MinClass = /** @class */ (function () {
    function MinClass() {
        this.list = [];
    }
    MinClass.prototype.add = function (value) {
        this.list.push(value);
    };
    MinClass.prototype.min = function () {
        var minVal = this.list[0];
        for (var i = 0; i < this.list.length; i++) {
            if (minVal > this.list[i]) {
                minVal = this.list[i];
            }
        }
        return minVal;
    };
    return MinClass;
}());
var m1 = new MinClass(); // 实例化类，并且指定了类的T代表的是number类型
// m1.add('ad');                               // 报错
m1.add(1); // 正确
m1.add(99); // 正确
m1.add(2); // 正确
console.log(m1.min()); // 1
var m2 = new MinClass(); // 实例化类，并且指定了类的T代表的是number类型
m2.add('a'); // 正确
// m2.add(1);                                  // 报错
m2.add('g'); // 正确
m2.add('z'); // 正确
console.log(m2.min()); // 'a'
