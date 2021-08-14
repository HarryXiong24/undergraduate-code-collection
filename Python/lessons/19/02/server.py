import socket               # 导入socket模块
host = socket.gethostname() # 获取主机地址
port = 12345                # 设置端口号   
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM) #创建TCP/IP套接字
s.bind((host,port)) # 绑定地址（host,port）到套接字
s.listen(1) # 设置最多连接数量
sock,addr = s.accept() # 被动接受TCP客户端连接
print('连接已经建立') 
info = sock.recv(1024).decode() # 接收客户端数据
while info != 'byebye':  # 判断是否退出
  if info :
    print('接收到的内容:'+info)
  send_data = input('输入发送内容：')   # 发送消息
  sock.send(send_data.encode()) # 发送TCP数据
  if send_data =='byebye':  # 如果发送exit,则退出
    break
  info = sock.recv(1024).decode() # 接收客户端数据
sock.close() # 关闭客户端套接字
s.close()    # 关闭服务器端套接字