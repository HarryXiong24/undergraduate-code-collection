#!/bin/bash


#该shell脚本主要用于测试shell程序设计中的read命令的使用，可以使用read命令对变量进行赋值
# 使用方式： read 变量1 变量2 变量3 .....
#
#read命令读取一个输入行，直到遇到换行符为止。
#遵循以下规则：
#多个数据或变量之间用空格分开
#若变量的个数等于输入数据的个数，则直接对应赋值
#若变量个数大于输入数据的个数，则没有输入数据的变量取空值
#若变量个数小于输入数据的个数，则将多余的数据赋值给最后一个变量
echo please input:name age grade
read name age grade
echo "name: $name"
echo "age : $age"
echo "grade: $grade"


#如果read读取的只有一个变量，那么输入行上面一整行数据都将赋值给该变量，无论该行上面是否有空格
echo plese input your university and province
read university
read province
echo university: $university
echo province : $province
#即：如果需要通过读入赋值的变量，可能的赋值包含空格，那么所在行的read命令不能同时读取其他变量，即该行read命令只读取该变量的值。因为shell会根据空格将输入的值进行分割。
