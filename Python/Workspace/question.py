# 编写程序，在D 盘根目录下创建一个文本文件 test.txt，并向其中写入字符串 hello world。

# fp = open(r'D:\test.txt', 'a+')
# print('hello world', file = fp)
# fp.close()

# 编写程序，生成一个包含 20 个随机整数的列表，然后对其中偶数下标的元素进行降序排列，奇数下标的元素不变。（提示：使用切片。）

# import random
# x = [random.randint(0, 100) for i in range(20)]
# y = x[::2]
# y.sort(reverse=True)
# x[::2] = y

# 编写函数，判断一个数字是否为素数，是则返回字符串 YES，否则返回字符串 NO。

# import math
# def IsPrime(v):
#   n = int(math.sqrt(v) + 1)
#   for i in range(2, n):
#     if v % i == 0:
#       return 'No'
#   else:
#     return 'Yes'

# 编写函数，模拟 Python 内置函数 sorted()。

# def Sorted(v):
#   t = v[::]
#   r = []
#   while t:
#     tt = min(t)
#     r.append(tt)
#     t.remove(tt)
#   return r

# 编写程序，生成包含 20 个随机数的列表，然后将前 10 个元素升序排列，后 10 个元素降序排列，并输出结果。

# import random
# x = [random.randint(0, 100) for i in range(20)]
# y = x[0:10]
# y.sort()
# x[0:10] = y
# y = x[10:20]
# y.sort(reverse=True)
# x[10:20] = y
# print(x) 

# 下面代码的功能是,随机生成50个介于[1,20]之间的整数,然后统计每个整数出现频率。

import random

x = [random.randint(1, 20) for i in range(50)]
r = dict()
for i in x:
  r[i] = r.get(i, 0) + 1
for k, v in r.items():
  print(k, v)

# 输入一行字符,分别统计出其中英文字母、空格、数字和其它字符的个数。

def main():
  s = input('input a string')
  letter = 0
  space = 0
  digit = 0
  other = 0

  for c in s:
    if c.isalpha():
      letter += 1
    if c.isspace():
      space += 1
    if c.isdigit():
      digit += 1
    else:
      other += 1

# 有 n 个乒乓球运动员打淘汰赛，编写函数计算至少需要多少场比赛才能决出冠军，不允许直接使用 n-1。

def demo(n):
  if n == 1:
    return 0
  if n == 2:
    return 1
  m, c = divmod(n, 2)
  return m + demo(c+m)