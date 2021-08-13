import socket # 导入socket模块

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)        #创建UDP套接字
data = input('请输入要转换的温度（单位：设置度）：')     #输入要转化的温度
s.sendto(data.encode(), ('127.0.0.1', 8888))               # 发送数据
print(s.recv(1024).decode()) # 打印接收数据:
s.close() # 关闭套接字
