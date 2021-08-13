print("\n","="*25,"蚂蚁庄园动态","="*25,"\n")
with open('message.txt','r') as file:   # 打开保存蚂蚁庄园动态信息的文件
    message = file.read()    # 读取全部动态信息
    print(message)           # 输出动态信息
    print("\n","="*29,"over","="*29,"\n")
