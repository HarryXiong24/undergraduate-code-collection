str1 = '@明日科技 @扎克伯格 @盖茨'
list1 = str1.split(' ')  # 用空格分割字符串
print('您@的好友有：')
for item in list1:
    print(item[1:])     # 输出每个好友名时，去掉@符号
 
