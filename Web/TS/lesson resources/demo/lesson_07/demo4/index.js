"use strict";
var MinClass = /** @class */ (function () {
    function MinClass() {
        this.list = [];
    }
    MinClass.prototype.add = function (value) {
        this.list.push(value);
    };
    MinClass.prototype.min = function () {
        var minNum = this.list[0];
        for (var i = 0; i < this.list.length; i++) {
            if (minNum > this.list[i]) {
                minNum = this.list[i];
            }
        }
        return minNum;
    };
    return MinClass;
}());
var m1 = new MinClass();
m1.add(1);
m1.add(3);
m1.add(2);
// m1.add('123');                  // 报错
console.log(m1.min()); // 1
var m2 = new MinClass();
m2.add('b');
m2.add('z');
m2.add('a');
console.log(m2.min()); // 'a'
