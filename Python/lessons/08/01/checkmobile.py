import re  # 导入Python的re模块

pattern = r'(13[4-9]\d{8})|(15[01289]\d{8})$'
mobile = '13634222222'
match = re.match(pattern,mobile)  # 进行模式匹配
if match == None:  # 判断是否为None,为真表示匹配失败
    print(mobile,'不是有效的中国移动手机号码。')
else:
    print(mobile,'是有效的中国移动手机号码。')
    
mobile = '13144222221'
match = re.match(pattern,mobile)  # 进行模式匹配
if match == None:   # 判断是否为None,为真表示匹配失败
    print(mobile,'不是有效的中国移动手机号码。')
else:
    print(mobile,'是有效的中国移动手机号码。')

