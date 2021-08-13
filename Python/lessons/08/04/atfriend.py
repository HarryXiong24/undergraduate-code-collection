import re
str1 = '@明日科技 @扎克伯格 @盖茨'
pattern = r'\s*@'
list1 = re.split(pattern,str1)  # 用空格和@或单独的@分割字符串
print('您@的好友有：')
for item in list1:
    if item != "":      # 输出不为空的元素
        print(item)     # 输出每个好友名
