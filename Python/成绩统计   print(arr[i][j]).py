print("请输入人数:")
n=int(input())
print("请输入成绩")
arr=[]
for i in range(n):
    arr.append(int(input()))                #记住一定要写成数据型，不能用字符型
print(arr)
print(type(arr))
print(sorted(arr))
print(sum(arr))
aver=sum(arr)/n
print(aver,"\n")

