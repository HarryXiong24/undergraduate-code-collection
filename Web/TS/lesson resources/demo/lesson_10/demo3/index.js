"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
// 类装饰器
function logClass(param) {
    return function (target) {
        console.log(target);
        console.log(param);
    };
}
// 属性装饰器
function logProperty(param) {
    /* target:原型函数   attr:成员名字 */
    return function (target, attr) {
        console.log(target); // [object]
        console.log(attr); // url
        target[attr] = param;
    };
}
var HttpClient = /** @class */ (function () {
    function HttpClient() {
    }
    HttpClient.prototype.getData = function () {
        return this.url;
    };
    __decorate([
        logProperty('www.badu.com'),
        __metadata("design:type", Object)
    ], HttpClient.prototype, "url", void 0);
    HttpClient = __decorate([
        logClass('xxxx'),
        __metadata("design:paramtypes", [])
    ], HttpClient);
    return HttpClient;
}());
var h = new HttpClient();
console.log(h.getData()); // 'www.badu.com'
