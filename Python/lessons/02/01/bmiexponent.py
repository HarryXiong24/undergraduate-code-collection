# -*- coding:utf-8 -*-

'''
   @ 功能：根据身高、体重计算BMI指数
   @ author:无语
   @ create:2018-3-30

'''

height = 1.70      # 保存身高的变量，单位：米
print("您的身高：" + str(height))
weight = 48.5      # 保存体重的变量，单位：千克
print("您的体重：" + str(weight))
bmi=weight/(height*height)      # 用于计算BMI指数，公式为“体重/身高的平方”
print("您的BMI指数为："+str(bmi))  #输出BMI指数
# 判断身材是否合理
if bmi<18.5:
    print("您的体重过轻 ~@_@~")
if bmi>=18.5 and bmi<24.9:
    print("正常范围，注意保持 (-_-)")
if bmi>=24.9 and bmi<29.9:
    print("您的体重过重 ~@_@~")
if bmi>=29.9:
    print("肥胖 ^@_@^")
