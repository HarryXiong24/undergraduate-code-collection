def String(s):
	a=b=c=d=0
	for i in s:
		if 'A'<=i<='Z':
			a+=1
		elif 'a'<=i<='z':
			b+=1
		elif '0'<=i<='9':
			c+=1
		else:
			d+=1
	return a,b,c,d

s=input("String is:")
a,b,c,d=String(s)
print(a,b,c,d)
