#!/bin/bash

result=$(ps aux | grep nginx | grep -v "grep")

if [ -n "$result" ]
then
	echo $result
else
	echo "nginx is not open!"
fi
