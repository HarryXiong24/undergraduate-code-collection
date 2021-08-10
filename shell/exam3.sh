select choice in Show List DirectoryM FileM Shell AcountM Exit
do
	case "$choice" in
		Show)echo "`date`" ; echo "`pwd`"
			break;;
		List)echo "`who`"
			break;;
		DirectoryM)mkdir /root/2018121015
			break;;
		FileM)touch a.txt
			break;;
		Shell)for((i=1;i<=10;i++))
			do
				((sum=sum+i))
			done
			echo "sum=$sum"
			break;;
		AcountM)groupadd net101
			useradd 2018121015
			usermod -a -G net101 2018121015
			break;;
		Exit)exit
			break;;
	esac
done
