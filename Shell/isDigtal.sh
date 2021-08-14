#!/bin/bash

read -p "please input a number:" number
test=$(echo $number | sed 's/[0-9]//g')
if [ -z "$test" ]
 then 
   echo "number is digtal"
 else
   echo "number is not digtal"
fi
