def division():
    '''功能：分苹果'''
    print("\n===================== 分苹果了 =====================\n")
    apple = int(input("请输入苹果的个数："))        # 输入苹果的个数
    children = int(input("请输入来了几个小朋友：")) 
    result = apple//children                        # 计算每人分几个苹果
    remain =apple-result*children                   # 计算余下几个苹果
    if remain>0:
        print(apple,"个苹果，平均分给",children,"个小朋友，每人分",result,
              "个,剩下",remain,"个。")
    else:
        print(apple,"个苹果，平均分给",children,"个小朋友，每人分",result,"个。")
if __name__ == '__main__':
    try:                                        # 捕获异常
        division()                              # 调用分苹果的函数
    except ZeroDivisionError:                   # 处理异常
        print("\n出错了 ~_~ ——苹果不能被0个小朋友分！")
        
    # 以下内容为捕获ValueError异常的代码，需要时打开前面的注释即可
##    except ValueError as e:                    # 处理ValueError异常
##        print("输入错误：",e)                   # 输出错误原因


