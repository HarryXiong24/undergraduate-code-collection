'''圆形模块'''
import math
PI = math.pi   # 圆周率
def girth(r):
    '''功能：计算周长
       参数：r（半径)
'''
    return round(2 * PI * r ,2 )  # 计算周长并保留两位小数

def area(r):
    '''功能：计算面积
       参数：r（半径)
'''
    return round(PI * r * r ,2)  # 计算面积并保留两位小数
if __name__ == '__main__':
    print(girth(10))
