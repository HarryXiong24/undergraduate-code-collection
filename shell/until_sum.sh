#!/bin/bash

i=1
s=0
#注意until和后面[]之间的空格，如果少写了这个空格是要报错的
until [ $i -gt 100 ]
	do
		s=$(($s+$i))
		i=$(($i+1))
	done
echo "s = $s"
