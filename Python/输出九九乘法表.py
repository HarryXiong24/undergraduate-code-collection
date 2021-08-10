#打印九九乘法表
n=int(input("n:"))
for i in range(1,n+1):
    for j in range(1,i+1):
        print(str(i)+'*'+str(j)+'='+str(i*j)+'\t',end='')#python中'',""无区别
    print("")
