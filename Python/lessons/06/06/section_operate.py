python = set(['绮梦','冷伊一','香凝','梓轩'])       # 保存选择Python语言的学生名字
c = set(['冷伊一','零语','梓轩','圣博'])             # 保存选择C语言的学生名字
print('选择Python语言的学生有：',python)            # 输出选择Python语言的学生名字
print('选择C语言的学生有：',c)      # 输出选择C语言的学生名字
print('交集运算：',python & c)      # 输出既选择了Python语言又选择C语言的学生名字
print('并集运算：',python | c)      # 输出参与选课的全部学生名字
print('差集运算：',python - c)      # 输出选择了Python语言但没有选择C语言的学生名字
