username_1 = '|MingRi|mr|mingrisoft|WGH|MRSoft|'   # 假设已经注册的会员名称保存在一个字符串中，以｜进行分隔
username_2 =username_1.lower()  # 将会员名称字符串转换为全部小写
regname_1 = input('输入要注册的会员名称：')
regname_2 = '|' + regname_1.lower() + '|'   # 将要注册的会员名称也转换为全部小写
if regname_2 in username_2:                 # 判断输入的会员名称是否存在
    print('会员名',regname_1,'已经存在！')
else:
    print('会员名',regname_1,'可以注册！')
