'''进行各种计算'''
from rectangle import *                       # 导入矩形模块
from circular import *                        # 导入圆形模块

if __name__ == '__main__':
    print("圆形的周长为：",girth(10))         # 调用计算圆形周长的方法
    print("矩形的周长为：",girth(10,20))      # 调用计算矩形周长的方法
# 以下为正常执行的代码，请将上面的代码删除，然后将下面代码的注释删除
'''
import rectangle as r                      # 导入矩形模块
import circular as c                       # 导入圆形模块

if __name__ == '__main__':
    print("圆形的周长为：",c.girth(10))         # 调用计算圆形周长的方法
    print("矩形的周长为：",r.girth(10,20))      # 调用计算矩形周长的方法
'''
