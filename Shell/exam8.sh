#！/bin/bash

#取出参数1中的文件名，并去除后缀

basename=`basename $1 .c`
outname="$basename.out"

#如果该文件已经存在，则删除最终可执行文件
if(test -f $outname) then
	rm $outname
fi

echo
echo ----------build message------------
gcc -Wall -g $1 -o $outname
echo
echo ---------result message------------
if(test -f $outname) then
	echo build succesfully!!
else echo build failed !!
fi
echo
