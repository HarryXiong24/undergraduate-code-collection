print("欢迎使用密码系统！输入yes进入该系统，no则退出")
choose=str(input("您的选择是："))
if choose=="no":
    print("欢迎下次使用！")
else:
    print("您有三次输入密码的机会！")
    for i in range(1,4):
        print("请第"+str(i)+"次输入：")
        password=str(input(""))
        if password=="123456":
            print("密码正确！")
            break
        else:
            printf("不好意思，输入错误！")
       
