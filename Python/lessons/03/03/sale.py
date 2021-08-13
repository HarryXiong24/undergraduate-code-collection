# -*- coding:utf-8 -*-

'''
   @ 功能：参加面包店的打折活动
   @ author:无语
   @ create:208-3-30
'''

print("面包店正在打折，活动进行中……")                             # 输出提示信息
strWeek = input("请输入中文星期（如星期一）：")                     # 输入星期，例如，星期一
intTime = int(input("请输入时间中的小时（范围：0~23）："))          # 输入时间，由于input()方法返回的结果为字符串类型，所以需要进行类型转换
# 判断是否满足活动参与条件（使用了if条件语句)
if (strWeek == "星期二" and  (intTime >= 19 and intTime <= 20)) or (strWeek == "星期六" and (intTime >= 17 and intTime <= 18)):
    print("恭喜您，获得了折扣活动参与资格，尽情选购吧！")           # 输出提示信息
else:
    print("对不起，您来晚一步，期待下次活动……")                   # 输出提示信息
