numberlist=[]                   # 定义一个空列表
a=6                              # 设置初始值
while True:
    if a%2==0:                   # 如果为偶数
        a=a//2
    else:                        # 如果为奇数
        a=a*3+1
    numberlist.append(a)         # 将生成的数添加到列表中
    if a==1:
      break;                     # 跳出循环
print("这个列表是",numberlist)   # 输出列表
