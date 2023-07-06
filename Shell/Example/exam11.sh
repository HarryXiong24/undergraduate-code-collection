#!/bin/bash

#通过source命令引用文件function.sh
source ./function.sh

echo please input the N:
read n

for i in 1 2 3 4 5 6 7 8
	do
		cube $i
		#通过预定义变量$? 获取函数返回值
		result=$?
		echo result=$result
		echo result_1=$result_1
	done