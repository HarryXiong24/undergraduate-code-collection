from settings.size import *   # 导入size模块下的全部定义

if __name__=='__main__':
    change(1024,768)  # 调用change()函数改变尺寸
    print('宽度：',getWidth())      # 输出宽度
    print('高度：',getHeight())     # 输出高度
