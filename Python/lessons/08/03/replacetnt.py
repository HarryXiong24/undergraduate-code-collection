import re  # 导入Python的re模块

pattern = r'(黑客)|(抓包)|(监听)|(Trojan)'  # 模式字符串

about = '我是一名程序员，我喜欢看黑客方面的图书，想研究一下Trojan。'
sub = re.sub(pattern,'@_@',about)  # 进行模式替换
print(sub)
    
about = '我是一名程序员，我喜欢看计算机网络方面的图书，喜欢开发网站。'
sub = re.sub(pattern,'@_@',about)   # 进行模式替换
print(sub)


