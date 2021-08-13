# -*- coding:utf-8 -*-

'''
   @ 功能：打印九九乘法表
   @ author:无语
   @ create:2018-3-30

'''

for i in range(1,10): 		# 输出9行
    for j in range(1, i + 1):  	# 输出与行数相等的列
        print(str(j) + "×" + str(i) + "=" + str(i * j) + "\t",end = '')
    print('')	                # 换行
	    




