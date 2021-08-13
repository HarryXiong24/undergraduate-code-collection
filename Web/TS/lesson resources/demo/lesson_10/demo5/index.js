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
var __param = (this && this.__param) || function (paramIndex, decorator) {
    return function (target, key) { decorator(target, key, paramIndex); }
};
function logParam(param) {
    return function (target, methodName, paramIndex) {
        console.log(param);
        console.log(target);
        console.log(methodName);
        console.log(paramIndex);
        /* 也能给对象增加属性 */
        target.apiUrl = 'hello world';
    };
}
var HttpClient = /** @class */ (function () {
    function HttpClient() {
    }
    HttpClient.prototype.getData = function (uuid) {
        console.log(uuid);
    };
    __decorate([
        __param(0, logParam('www.baidu.com')),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [Object]),
        __metadata("design:returntype", void 0)
    ], HttpClient.prototype, "getData", null);
    return HttpClient;
}());
var h = new HttpClient();
h.getData('123');
/**
 * 依次打印：
 * 1.'www.baidu.com'
 * 2.[getData: Function]
 * 3.getData
 * 4.0
 * 5.'123'
 */
console.log(h.apiUrl); // 'hello world'
