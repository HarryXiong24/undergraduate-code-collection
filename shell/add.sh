#!/bin/bash

num1=$1
num2=$2
sum=$(($num1+$num2))
echo $sum
#$*会把命令行的参数当成一个整体
echo "\$* the parameter is : $*"
for val in "$*"
	do
		echo $val
	done
#$#会把命令行的参数区分对待
echo "\$@ the parameter is : $@"
for val in "$@"
	do
		echo $val
	done
#$#是统计命令行参数的个数
echo "\$# the number of parameter is : $#"
