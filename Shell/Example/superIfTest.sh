#!/bin/bash

read -p "please input a digtal number:" number
#if [ $number -eq 1 || $number -eq 2 ]   # 报错，如果只有一个中括号不能够使用&& 或者 ||
#if [ $number -eq 1 -o $number -eq 2 ]
#if [ $number -eq 1 ] || [ $number -eq 2 ]
#if [[ $number -eq 1 || $number -eq 2 ]]
#我们可以用这种双括号来进行正则的匹配
if [[ $number =~ ^[1-9][0-9]* ]]
then
	echo "number is ok"
else
	echo "number is not ok"
fi
