def MyReverse(x):
	y=[i for i in range(len(x))]
	j=0
	for i in range(len(x)-1,-1,-1):
		y[j]=x[i]
		j+=1
	
	return y
	

x=[1,5,7,8,9,6,4]
print(MyReverse(x))

