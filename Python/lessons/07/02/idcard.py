programer_1 = '你知道我的生日吗？'    # 程序员甲问程序员乙的台词
print('程序员甲说：',programer_1)          # 输出程序员甲的台词
programer_2 = '输入你的身份证号码。'   # 程序员乙的台词
print('程序员乙说：',programer_2)          # 输出程序员乙的台词
idcard = '123456199006277890'    # 定义保存身份证号码的字符串
print('程序员甲说：',idcard)       # 程序员乙说出身份证号码
birthday = idcard[6:10] + '年' + idcard[10:12] + '月' + idcard[12:14] + '日'                    # 截取生日
print('程序员乙说：','你是' + birthday + '出生的，所以你的生日是' + birthday[5:])        # 输出程序员乙的生日
