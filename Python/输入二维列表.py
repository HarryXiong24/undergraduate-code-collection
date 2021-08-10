arr=[]
m=int(input("input m:"))                     #规定二维列表的行和列
n=int(input("input n:"))
for i in range(m):
    arr.append([])                           #列表里在创建一个列表
    for j in range(n):
        arr[i].append(input())               #向列表里输入元素
print(type(arr))
print("\n")
print(arr)                                  #输出二维列表
print("\n")
for i in range(m):                            #输出矩阵形式
    for j in range(n):
        if j==n-1:
           print(arr[i][j])
        else:
           print(arr[i][j],end="")
        
    
