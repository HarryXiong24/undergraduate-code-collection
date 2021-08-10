x=eval(input())
t=x
i=2
res=[]
while  True:
	if t==1:
		break
	if t%i==0:
		res.append(i)
		t=t//i
	else:
		i+=1
print(res)
