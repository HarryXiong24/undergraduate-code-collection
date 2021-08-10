import random

x=[random.randint(0,100) for i in range(20)]
print(x)

s=x[0:20:2]
print(s)
s1=sorted(s,reverse=True)
print(s1)