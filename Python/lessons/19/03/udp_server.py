import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) #创建UDP套接字
s.bind(('127.0.0.1', 8888)) # 绑定地址（host,port）到套接字
print('绑定UDP到8888端口')
# 接收数据:
data, addr = s.recvfrom(1024)
data = float(data)*1.8 + 32 # 转化公式
send_data = '转换后的温度（单位：华氏温度）：'+str(data)
print('Received from %s:%s.' % addr)
s.sendto(send_data.encode(), addr) # 发送给客户端
s.close()    # 关闭服务器端套接字