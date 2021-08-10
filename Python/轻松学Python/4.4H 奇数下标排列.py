import random

x=[random.randint(0,100) for i in range(50)]
print(x)
for i in range(50)[::-1]:        #关键点
	if x[i]%2!=0:
		del x[i]
print(x)