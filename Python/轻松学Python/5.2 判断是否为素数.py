def p(num):
	if  num==1:
		print("是素数")
	for i in range(2,num):
		if num%i==0:
			print("不是素数")
			break
		if i==num-1:
			print("是素数")


num=int(input("请输入一个数:(num>0)"))
p(num)