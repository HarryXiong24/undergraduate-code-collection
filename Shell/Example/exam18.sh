if [ -e $filename ] then
	echo $filename exist
elif [ -b $filename ] then
	echo This is block file
elif [ -c $filename ] then
    echo This is character file
elif [ -f $filename ] then
    echo This is a normal file
else [ -d $filename ] then
    echo This is a dirctory file
fi
