# -*- coding:utf-8 -*-

'''
   @ 功能：模拟超市抹零结账行为
   @ author:无语
   @ create:2018-3-30

'''

money_all = 56.7 + 72.9 + 88.5 + 26.6 + 68.8  # 累加总计金额
money_all_str = str(money_all)                # 转换为字符串
print("商品总金额为：" + money_all_str)
money_real = int(money_all)                   # 进行抹零处理
money_real_str = str(money_real)              # 转换为字符串
print("实收金额为：" + money_real_str)
