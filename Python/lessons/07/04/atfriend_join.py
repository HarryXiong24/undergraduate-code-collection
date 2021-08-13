list_friend = ['明日科技','扎克伯格','盖茨']  # 好友列表
str_friend = ' @'.join(list_friend)  # 用空格+@符号进行连接
at = '@'+str_friend  # 由于使用join()方法合并时，第一个元素前不加分隔符，所以需要在前面加上@符号
print('您要@的好友：',at)

