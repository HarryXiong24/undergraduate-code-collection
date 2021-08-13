import re  # 导入Python的re模块

pattern = r'(黑客)|(抓包)|(监听)|(Trojan)'  # 模式字符串

about = '我是一名程序员，我喜欢看黑客方面的图书，想研究一下Trojan。'
match = re.search(pattern,about)  # 进行模式匹配
if match == None:  # 判断是否为None,为真表示匹配失败
    print(about,'@ 安全！')
else:
    print(about,'@ 出现了危险词汇！')
    
about = '我是一名程序员，我喜欢看计算机网络方面的图书，喜欢开发网站。'
match = re.match(pattern,about)  # 进行模式匹配
if match == None:   # 判断是否为None,为真表示匹配失败
    print(about,'@ 安全！')
else:
    print(about,'@ 出现了危险词汇！')

