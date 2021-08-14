#!/bin/bash

read -p "please input yes or no: " choose
  case $choose in
    "yes")
       echo "you choose yes!"	
         ;;
    "no")
       echo "you choose no!"
         ;;
    *)
       echo "you choose others!"
         ;;
  esac
