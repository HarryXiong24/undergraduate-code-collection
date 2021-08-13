#!/bin/bash

cd /Users/yizijun/学习资料/shell-study-dir
ls *.tar.gz > tmp.log
for i in $( cat tmp.log )
	do
		#&> 把正确和错误信息都以覆盖的方式写入/dev/null中
		tar -zxf $i &> /dev/null
	done

rm -rf tmp.log
