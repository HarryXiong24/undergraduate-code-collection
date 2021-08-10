import random

x=[random.randint(0,100) for i in range(20)]
print(x)
a=sorted(x[:10])
b=sorted(x[10:],reverse=True)
print(a)
print(b)