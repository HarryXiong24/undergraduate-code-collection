#slect循环：
#使用select循环将会在屏幕上生成一个数字化的菜单，并提示用户进行选择，默认的提示符是：”#“。用户只需在提示符下输入对应菜单的数字，即可完成选择。
#如下所示，item-list列表是一个字符串组成的序列，当用户选择数字以后，将会将相应的菜单值赋值给string变量，并执行select循环体内容。
#select经常与cast一起使用，允许用户在菜单中选择，并基于选择执行相应的命令，当执行到break语句时候，将退出select结构
#select是一个循环体，可以使用break退出循环。
# select string in item-list 
# do
#   command
# done
echo selcet 测试
select i in 星期一 星期二 星期三 星期四 星期五 星期六 星期日
do
{
	case $i in
	星期一) echo 您选择的是周一;break;;
	星期二) echo 今天是星期二;;
	星期三) echo 您选择的是周三; break;;
	*) echo 今天既不是周一也不是周二更不是周三;;
	esac
}
done