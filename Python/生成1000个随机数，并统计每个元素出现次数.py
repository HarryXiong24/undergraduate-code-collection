import random

x=[random.randint(0,100) for i in range(1000)]
s=set(x)
for v in s:
	print(v,":",x.count(v))
	