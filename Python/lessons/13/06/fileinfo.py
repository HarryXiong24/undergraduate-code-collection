import os   # 导入os模块
fileinfo = os.stat("mr.png") # 获取文件的基本信息
print("文件完整路径：", os.path.abspath("mr.png")) # 获取文件的完整数路径
# 输出文件的基本信息
print("索引号：",fileinfo.st_ino)
print("设备名：",fileinfo.st_dev)
print("文件大小：",fileinfo.st_size," 字节")
print("最后一次访问时间：",fileinfo.st_atime)
print("最后一次修改时间：",fileinfo.st_mtime)
print("最后一次状态变化时间：",fileinfo.st_ctime)

'''*********************以下内容为修改后的代码*************************'''
##import os   # 导入os模块
##
##def formatTime(longtime):
##    '''格式化日期时间的函数
##       longtime：要格式化的时间
##    '''
##    import time  # 导入时间模块
##    return time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(longtime))
##def formatByte(number):
##    '''格式化日期时间的函数
##       number：要格式化的字节数
##    '''    
##    for (scale,label) in [(1024*1024*1024,"GB"),(1024*1024,"MB"),(1024,"KB")]:
##        if number>= scale:   # 如果文件大小大于等于1KB
##            return "%.2f %s" %(number*1.0/scale,label)
##        elif number == 1: # 如果文件大小为1字节
##            return "1 字节"
##        else:   # 处理小于1KB的情况
##            byte = "%.2f" % (number or 0) 
##    return (byte[:-3] if byte.endswith('.00') else byte)+" 字节"  # 去掉结尾的.00，并且加上单位“字节”
##
##
##if __name__ == '__main__':
##    fileinfo = os.stat("mr.png") # 获取文件的基本信息
##    print("文件完整路径：", os.path.abspath("mr.png")) # 获取文件的完整数路径
##    # 输出文件的基本信息
##    print("索引号：",fileinfo.st_ino)
##    print("设备名：",fileinfo.st_dev)
##    print("文件大小：",formatByte(fileinfo.st_size))
##    print("最后一次访问时间：",formatTime(fileinfo.st_atime))
##    print("最后一次修改时间：",formatTime(fileinfo.st_mtime))
##    print("最后一次状态变化时间：",formatTime(fileinfo.st_ctime))
##
