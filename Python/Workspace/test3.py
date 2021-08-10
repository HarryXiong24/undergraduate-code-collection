# fp = open(r'D:\test.txt', 'a+')
# print('hello world', file = fp)
# fp.close()

# import math
# import random
# x = [random.randint(0, 100) for i in range(20)]
# print(x)
# y = x[::2]
# y.sort(reverse=True)
# print(y)
# x[::2] = y
# print(x)

# import math 

# def IsPrime(v):

#   n = int(math.sqrt(v)+1)

#   for i in range(2, n):
#     if v % i == 0:
#       return 'No'
#   else:
#     return 'Yes'

# print(IsPrime(7))


# def Sorted(v):
#   t = v[::]
#   r = []
#   while t:
#     temp = min(t)
#     r.append(temp)
#     t.remove(temp)

#   return r

# import random
# x = [random.randint(0,100) for i in range(20)]
# print(x)
# y = x[0:10]
# y.sort()
# x[0:10] = y
# y = x[10:20]
# y.sort(reverse=True)
# x[10:20] = y
# print(x)

import re
import string
import random

x = ['11', '2', '3']
print(max(x))

s = 'sdad'
with open('sample.txt', 'w') as fp:
  fp.write(s)
