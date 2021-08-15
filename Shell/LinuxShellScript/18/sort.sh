#!/bin/bash

ls -al | sort -k 5 -r 
# -k 指定字段编号 , 默认分隔符为制表符
# -r 表示反序排列
# -t 可以指定分隔符
# -n 表示将字符串变成数字来排序 , 而不是按照字符串排序