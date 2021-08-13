'''矩形模块'''
def girth(width,height):
    '''功能：计算周长
       参数：width（宽度)、height（高)
'''
    return (width + height)*2

def area(width,height):
    '''功能：计算面积
       参数：width（宽度)、height（高)
'''
    return width * height
if __name__ == '__main__':
    print(area(10,20))
