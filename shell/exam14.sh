#for循环有两种风格：有" in list-values "; 没有" in list-values ";
#第一种：将由空格分隔的值列表中的每一个值依次赋给变量variable并执行循环体，当列表中的所有值都已经赋给variable一遍以后，循环终止；
# for variable [ in list-values ] 
# do
#   command
# done
echo for循环测试
for i in 2 4 6 8 10
do
{
	echo $i
}
done
#第二种：如果没有 " in list-values "那么系统会将该程序的位置参数当作list-values。将位置参数依次赋给变量variable，直到所有参数都已经赋过一遍以后才会终止； 
# for variable
# do
#   command
# done 
for i
do
{
	echo $i
}
done