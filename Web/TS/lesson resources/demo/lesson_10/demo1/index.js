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
function logClass(param) {
    console.log(param);
    // param就是当前类
    param.prototype.apiUrl = '动态扩展的属性';
    param.prototype.run = function () {
        console.log('我是一个run方法');
    };
}
let HttpClient = class HttpClient {
    constructor() {
    }
    getData() {
    }
};
HttpClient = __decorate([
    logClass,
    __metadata("design:paramtypes", [])
], HttpClient);
const h = new HttpClient();
console.log(h.apiUrl); // '动态扩展的属性'
h.run(); // '我是一个run方法'
