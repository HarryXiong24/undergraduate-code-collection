print("        长歌行")
verse = ["青青园中葵","朝露待日晞","阳春布德泽","万物生光辉","常恐秋节至","焜黄华叶衰",
         "百川东到海","何时复西归","少壮不努力","老大徒伤悲"]
for index,item in enumerate(verse):
    if index%2 == 0:                       # 判断是否为偶数，为偶数时不换行
        print(item+"，", end='')
    else:
        print(item+"。")                   # 换行输出
