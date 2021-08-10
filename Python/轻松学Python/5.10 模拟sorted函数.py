def MySorted(x,reverses=False):
	if reverses==False:
		for j in range(len(x),1,-1):
			for i in range(1,j):
				if x[i]<x[i-1]:
					temp=x[i]
					x[i]=x[i-1]
					x[i-1]=temp
	if reverses==True:
		for j in range(len(x),1,-1):
			for i in range(1,j):
				if x[i]>x[i-1]:
					temp=x[i]
					x[i]=x[i-1]
					x[i-1]=temp
	
	return x
	

x=[1,5,7,8,9,6,4]
print(MySorted(x))
print(MySorted(x,reverses=True))
