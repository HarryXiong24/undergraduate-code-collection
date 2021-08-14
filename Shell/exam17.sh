#!/bin/bash

# shell测试命令： test 表达式
# 可以使用 [ 表达式 ]代替test命令，但是要注意在"["之后和"]"之前保留空格。


# 测试文件属性：
# -b file      如果为块文件，则表达式为真
# -c file      如果为字符设备，则表达式为真
# -r/w/x file  如果文件存在且为 可读/可写/执行 文件时候，表达式为真
# -s file      如果文件存在且为普通文件，并且长度大于零
# -d file      如果为目录，则表达式值为真
# -f file      如果文件为普通文件，则表达式为真
# -e file      如果文件存在，表达式为真


echo please input the filename:
read filename

if [ -e $filename ]; then
	echo $filename exist
	if [ -b $filename ]; then
		echo This is block file
	elif [ -c $filename ]; then
 	    echo This is character file
	elif [ -f $filename ]; then
   	    echo This is a normal file
	elif [ -d $filename ]; then
   	    echo This is a dirctory file
	fi
else
	echo $filename not exist
fi
