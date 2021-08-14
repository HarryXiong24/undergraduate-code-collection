# -*- coding:utf-8 -*-
import socket               #导入socket模块
host = '127.0.0.1'          #主机IP
port = 8080                     #端口号
web = socket.socket()           #创建 socket 对象
web.bind((host,port))       #绑定端口
web.listen(5)               #设置最多连接数
print ('服务器等待客户端连接...') 
#开启死循环
while True:
    conn,addr = web.accept()    #建立客户端连接
    data = conn.recv(1024).decode()      #获取客户端请求数据
    print(data)             #打印接受数据
    conn.sendall(b'HTTP/1.1 200 OK\r\n\r\nHello World')     #向客户端发送数据
    conn.close()            #关闭链接 
