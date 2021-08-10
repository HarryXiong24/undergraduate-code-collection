import random

x=[random.randint(0,100) for i in range(1000)]
s=set(x)
sum=0;
for v in s:
	print(v,":",x.count(v))
	sum+=x.count(v)

print(sum)