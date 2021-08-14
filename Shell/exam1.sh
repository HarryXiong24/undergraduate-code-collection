if [ -d "$1" ]
then
	sum=0
	cd $1
	for i in *.txt
	do
		if [ -f "$i" ]
		then
			a=`cat $i|wc -l`
			((sum+=a))
		fi
	done
	echo "$sum"
elif [ -f "$1" ]
then
	echo "Not dir!"
else
	echo "Input Error!"
fi
