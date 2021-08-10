print("欢迎进入最大数比较系统！")
for i in range(1,100):
    a=float(input("请输入a:"))
    b=float(input("请输入b:"))
    if a>b:
        r=a
    else:
        r=b
    print("更大数为:",r)
    print("是否选择结束？yes or no")
    q=str(input("请输入："))
    if q=="yes":
        print("本次体验已经结束！")
        break

    
