#!/bin/bash


#shell提供了五种循环控制语句：while、until、for、forin、select；


# while command
# do 
#   command
# done
echo while测试
i=1
while(test $i -le 10)
do
{
	echo $i
#expr命令是一个表达式处理命令。如下所示，需要将该命令连同表达式放在反引号中。
	i=`expr $i + 1`
}
done
