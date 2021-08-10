#!/bin/bash

# 定义数组： data=(element1 element2 ....) 要特别注意，元素之间没有逗号。
#
# 在使用下标引用某一个数组变量的时候，通常要使用${data[i]} 即：使用{ }将要引用的变量括起来，以保证shell将会将data[i]当作一个完整的变量来解析。如果使用 $data[i]引用数组中的某一个变量， shell可能会将$data当作一个单独的变量来引用，而不能将 data[i]当作一个变量来引用.
#
# shell中和其他语言一样，数组名可以表示该数组中的第一个元素。

data=(masic007 hello world xidian university)

# $data[0] 这种引用，shell将会将data当作一个变量来解析，而不能将data[0]整体当作变量来解析
echo $data[0]

#以下引用可以正确的引用到数组中的值
echo data[1]=${data[1]}
echo data[2]=${data[2]}
echo data[3]=${data[3]}


#特殊的索引标识： * @
#两者都可以引用整个数组中所有元素。
#但是如果使用在双引号中，有所不同。*表示将原数组中的所有元素当作一个元素赋值给新数组，新数组只有一个元素。@表示将原数组的内容复制到新数组，生成的新数组和原数组内容相同
echo 使用data[*]打印:${data[*]}
echo 使用data[@]打印:${data[@]}

newdata_1=("${data[*]}")
newdata_2=("${data[@]}")

echo newdata_1 length: ${#newdata_1[*]}
echo newdata_2 length: ${#newdata_2[*]}


#数组的元素个数：${#name[*]}
echo The number of elements of array： ${#data[*]}


#数组某个元素的长度: ${#name[i]}
echo Length of the 2nd data: ${#data[2]}
