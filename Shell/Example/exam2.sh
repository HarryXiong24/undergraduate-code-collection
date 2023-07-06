if [ "$1" -ge 2 -a "$1" -le 15 ]
then 
	for((i=1;i<="$1";i++))
	do
		if [ "$i" -eq 1 -o "$i" -eq "$1" ]
		then
			for((j=1;j<="$1";j++))
			do
				if [ "$j" -eq 1 -o "$j" -eq "$1" ]
				then
					echo -e "+\c"
				else
					echo -e "-\c"
				fi
			done
			echo ""
		else
			for((j=1;j<="$1";j++))
			do
				if [ "$j" -eq 1 -o "$j" -eq "$1" ]
				then
					echo -e "|\c"
				else
					echo -e " \c"
				fi
			done
			echo  ""
		fi
	done
else
	echo "Input Error!"
fi
	
