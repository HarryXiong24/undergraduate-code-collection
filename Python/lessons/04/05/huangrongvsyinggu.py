# -*- coding:utf-8 -*-

'''
   @ 功能：解决黄蓉难倒瑛姑的数学题（while循环版）
   @ author:无语
   @ create:2018-3-30

'''


print("今有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二，问几何？\n")
none = True                                                # 作为循环条件的变量
number = 0                                                  # 计数的变量
while none:
    number += 1                                             # 计数加1
    if number%3 ==2 and number%5 ==3 and number%7 ==2:  # 判断是否符合条件
        print("答曰：这个数是",number)                      # 输出符合条件的数
        none = False                                        # 将循环条件的变量赋值为否

