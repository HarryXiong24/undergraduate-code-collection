import socket       # 导入socket模块
s= socket.socket()  # 创建TCP/IP套接字
host = socket.gethostname() # 获取主机地址
port = 12345        # 设置端口号     
s.connect((host,port)) # 主动初始化TCP服务器连接
print('已连接')
info = ''           
while info != 'byebye':  # 判断是否退出
  send_data=input('输入发送内容：')    # 输入内容
  s.send(send_data.encode()) # 发送TCP数据
  if send_data =='byebye': # 判断是否退出
    break
  info = s.recv(1024).decode() # 接收服务器端数据
  print('接收到的内容:'+info)
s.close() # 关闭套接字