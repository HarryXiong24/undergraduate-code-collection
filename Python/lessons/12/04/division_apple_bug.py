def division():
    '''功能：分苹果'''
    print("\n===================== 分苹果了 =====================\n")
    apple = int(input("请输入苹果的个数："))           # 输入苹果的个数
    children = int(input("请输入来了几个小朋友："))
   
    assert apple > children ,"苹果不够分"
    
    result = apple//children                           # 计算每人分几个苹果
    remain =apple-result*children                      # 计算余下几个苹果
    if remain>0:
        print(apple,"个苹果，平均分给",children,"个小朋友，每人分",result,
               "个,剩下",remain,"个。")
    else:
        print(apple,"个苹果，平均分给",children,"个小朋友，每人分",result,"个。")
if __name__ == '__main__':
    division()                       # 调用分苹果的函数
    # 将assert语句和异常处理语句结合使用时，删除上面的division()语句，然后打开下面4行代码的注释
##    try:
##        division()                                    # 调用分苹果的函数
##    except AssertionError as e:
##        print("\n输入有误：",e)



