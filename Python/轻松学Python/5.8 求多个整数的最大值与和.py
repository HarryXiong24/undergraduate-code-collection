def List(x):
	a = max(x)
	b = sum(x)
	return a,b


x=[]
while True:
	i=eval(input("input a num:"))
	x.append(i)
	print("continue or not?(T or F)")
	c=input("")
	if c=='F':
		break
print(x)
a,b=List(x)
print(a,b)
