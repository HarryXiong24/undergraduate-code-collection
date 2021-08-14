#!/bin/sh
echo "This is echo command"

#This is a comment line

#This is a definition of a var
comment="This is comment"
#This is usage of a var
echo $comment


#单引号中的$将不会被当作变量计算，双引号中的$将会当作变量计算。

var="xidian university"

echo "This is $var"

echo 'This is $var'


#反斜线：通过前置反斜线，就可以引用任何元字符，包括$操作符。转义字符

echo "This is \$var"



#单引号:引用命令。将命令赋值给一个单引号的字符串。在以后就可以通过引用这个变量来执行这个命令。

result='ls -l'

$result

cd ..

$result

#反引号: `,一般位于键盘的左上角。同单引号不同的是，反引号中的命令会被首先执行，然后将结果赋值给一个变量，而不是保存命令本身。

#在testresult赋值的过程中，ls -l 命令已经执行，并将起结果保存在变量testresult中。所以，两次的echo $testresult将会输出同样的值
testresult=`ls -l`

echo $testresult

echo "--------------------------"

cd ..

echo $testresult
