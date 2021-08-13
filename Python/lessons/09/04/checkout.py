def fun_checkout(money):
    '''功能：计算商品合计金额并进行折扣处理
       money：保存商品金额的列表
       返回商品的合计金额和折扣后的金额
    '''
    money_old = sum(money)  # 计算合计金额
    money_new = money_old
    if money_old >= 500 and money_old <1000 :  # 满500可享受9折优惠
        money_new = '{:.2f}'.format(money_old*0.9)
    elif money_old >=1000 and money_old <= 2000:  # 满1000可享受8折优惠
        money_new = '{:.2f}'.format(money_old*0.8)
    elif money_old >=2000 and money_old <= 3000:  # 满2000可享受7折优惠
        money_new = '{:.2f}'.format(money_old*0.7)
    elif money_old >=3000 :                  # 满3000可享受6折优惠
        money_new = '{:.2f}'.format(money_old*0.6)
    return money_old,money_new   # 返回总金额和折扣后的金额
        
#*****************************调用函数***********************************#
print("\n开始结算……\n")
list_money = []    # 定义保存商品金额的列表
while True:
    # 请不要输入非法的金额，否则将抛出异常
    inmoney = float(input("输入商品金额（输入0表示输入完毕)："))
    if int(inmoney)==0:
        break     # 退出循环
    else:
        list_money.append(inmoney)  # 将金额添加到金额列表中
money = fun_checkout(list_money)  # 调用函数
print("合计金额：",money[0],"应付金额：",money[1])   # 显示应付金额



