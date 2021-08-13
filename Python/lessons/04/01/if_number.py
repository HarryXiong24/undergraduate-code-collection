# -*- coding:utf-8 -*-

'''
   @ 功能：判断输入的是不是黄蓉所说的数
   @ author:无语
   @ create:2018-3-30

'''
print("今有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二，问几何？\n")
number = int(input("请输入您认为符合条件的数："))     # 输入一个数
if number%3 ==2 and number%5 ==3 and number%7 ==2:
    print(number,"符合条件：三三数之剩二，五五数之剩三，七七数之剩二")
