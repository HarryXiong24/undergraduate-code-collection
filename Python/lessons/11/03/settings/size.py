_width = 800        # 定义保护类型的全局变量（宽度）
_height = 600       # 定义保护类型的全局变量（高度）
def change(w,h):
    global _width       # 全局变量（宽度）
    _width = w        # 重新给宽度赋值
    global _height      # 全局变量（高度）
    _height = h       # 重新给高度赋值
def getWidth():     # 获取宽度的函数  
    global _width
    return _width
def getHeight():     # 获取高度的函数  
    global _height
    return _height

if __name__ == '__main__':  # 测试代码
    change(1024,768)       # 调用change()函数
    print("宽度：",getWidth())      # 输出宽度
    print("高度：",getHeight())     # 输出高度
