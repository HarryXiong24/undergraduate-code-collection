# -*- coding:utf-8 -*-

'''
   @ 功能：解决黄蓉难倒瑛姑的数学题（for循环改进版）
   @ author:无语
   @ create:2018-3-30

'''

print("今有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二，问几何？\n")
for number in range(100):
##    print(number)
    if number%3 ==2 and number%5 ==3 and number%7 ==2:   # 判断是否符合条件
        print("答曰：这个数是",number)                       # 输出符合条件的数
        break          # 跳出for循环

