bookinfo = [('不一样的卡梅拉（全套)',22.50,120),('零基础学Android',65.10,89.80),
        ('摆渡人',23.40,36.00),('福尔摩斯探案全集8册',22.50,128)]
print('爬取到的商品信息：\n',bookinfo,'\n')
bookinfo.sort(key=lambda x:(x[1],x[1]/x[2]))    # 按指定规则进行排序
print('排序后的商品信息：\n',bookinfo)
