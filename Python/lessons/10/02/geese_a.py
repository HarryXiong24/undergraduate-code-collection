class Geese:
    '''雁类'''
    neck = "脖子较长"                       # 类属性（脖子）
    wing = "振翅频率高"                     # 类属性（翅膀）
    leg = "腿位于身份的中心支点，行走自如"  # 类属性（腿）
    number = 0                              # 编号
    def __init__(self):                     # 构造方法
        Geese.number += 1                   # 将编号加1
        print("\n我是第"+str(Geese.number)+"只大雁，我属于雁类！我有以下特征：")
        print(Geese.neck)    # 输出脖子的特征
        print(Geese.wing)    # 输出翅膀的特征
        print(Geese.leg)     # 输出腿的特征

# 创建4个雁类的对象（相当于有4只大雁)
list1 = []
for i in range(4):                         # 循环4次
     list1.append(Geese())                 # 创建一个雁类的实例
print("一共有"+str(Geese.number)+"只大雁")

# 以下代码为添加类属性的代码，删除上下的三引号即可正常运行
'''
Geese.beak = "喙的基部较高，长度和头部的长度几乎相等"  # 添加类属性
print("第2只大雁的喙：",list1[1].beak)    # 访问类属性

'''
