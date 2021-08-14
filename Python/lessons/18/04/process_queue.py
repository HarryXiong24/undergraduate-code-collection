# -*- coding: utf-8 -*-
from multiprocessing import Process, Queue

# 向队列中写入数据
def write_task(q):
    if not q.full():
        for i in range(5):
            message = "消息" + str(i)
            q.put(message)
            print("写入:%s"%message)
# 从队列读取数据
def read_task(q):
    while not q.empty():
        print("读取:%s" % q.get(True,2)) # 等待2秒，如果还没读取到任何消息，则抛出"Queue.Empty"异常

if __name__ == "__main__":
    print("-----父进程开始-----")
    q = Queue()  # 父进程创建Queue，并传给各个子进程
    pw = Process(target=write_task, args=(q,))      # 实例化写入队列的子进程，并且传递队列
    pr = Process(target=read_task, args=(q,))       # 实例化读取队列的子进程，并且传递队列
    pw.start()   # 启动子进程 pw，写入
    pr.start()   # 启动子进程 pr，读取
    pw.join()    # 等待 pw 结束
    pr.join()    # 等待 pr 结束
    print("-----父进程结束-----")