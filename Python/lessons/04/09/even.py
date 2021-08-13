# -*- coding:utf-8 -*-

'''
   @ 功能：计算100以内所有偶数的和
   @ author:无语
   @ create:2018-3-30

'''
total = 0     # 用于保存累加和的变量
for number in range(1,100):
    if number%2 == 1:   # 判断是否符合条件
        continue        # 继续下一次循环
    total += number     # 累加偶数的和
print("1到100之间（不包括100）的偶数和为：",total)   # 输出累加结果

