class Geese:
    '''大雁类'''
    def __init__(self,beak,wing,claw):    # 构造方法
        print("我是大雁类！我有以下特征：")
        print(beak)    # 输出喙的特征
        print(wing)    # 输出翅膀的特征
        print(claw)    # 输出爪子的特征
    def fly(self,state):  # 定义飞行方法
        print(state)
     
'''**************调用方法*********************'''

beak_1 = "喙的基部较高，长度和头部的长度几乎相等"    # 喙的特征
wing_1 = "翅膀长而尖"      # 翅膀的特征
claw_1 = "爪子是蹼状的"                # 爪子的特征
wildGoose = Geese(beak_1,wing_1,claw_1)        # 创建大雁类的实例
wildGoose.fly("我飞行的时候，一会儿排成个人字，一会排成个一字")  # 调用实例方法
