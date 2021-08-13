# -*- coding:utf-8 -*-

'''
   @ 功能：计算学生成绩的分差及平均分
   @ author:无语
   @ create:2018-3-30

'''

python = 95                          # 定义变量，存储Python的分数
english = 92                         # 定义变量，存储English的分数
c = 89                               # 定义变量，存储C语言的分数
sub = python - english               # 计算Python和C语言的分数差
avg = (python + english + c) / 3     # 计算平均成绩
print("Python课程和C语言课程的分数之差： " + str(sub) + " 分\n")
print("3门课的平均分： " + str(avg) + " 分")

