# -*- coding:utf-8 -*-

'''
   @ 功能：判断输入的年份是不是闰年
   @ author:无语
   @ create:2018-3-30

'''

year = int(input("请输入一个年份："))   # 获取用户输入的年份，并转换为整型
if year % 4 == 0:                      # 四年一闰
    if year % 100 == 0:
        if year % 400 == 0:            # 四百年再闰
           print(year,"年是闰年")
        else:                           # 百年不闰
            print(year,"年不是闰年")
    else:
        print(year,"年是闰年")
else:
    print(year,"年不是闰年")
