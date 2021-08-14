#until循环：与while循环判断条件相反。当且仅当command1命令结果为真时候退出循环，否则执行循环体 (do和done之间的语句) 
# until 
#   command1
# do
#   command2
# done
echo until 测试
i=1
until
[ $i -ge 10 ]
do
{
	echo $i
	let i=i+1
}
done