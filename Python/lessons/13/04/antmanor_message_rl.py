print("\n","="*35,"蚂蚁庄园动态","="*35,"\n")
with open('message.txt','r') as file:   # 打开保存蚂蚁庄园动态信息的文件
    number = 0   # 记录行号
    while True:
        number += 1
        line = file.readline()
        if line =='':
            break    # 跳出循环
        print(number,line,end= "\n")  # 输出一行内容
print("\n","="*39,"over","="*39,"\n")
