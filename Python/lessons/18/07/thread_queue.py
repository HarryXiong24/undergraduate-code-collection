# -*- coding: utf-8 -*-
from queue import Queue
import random,threading,time

#生产者类
class Producer(threading.Thread):
    def __init__(self, name,queue):
        threading.Thread.__init__(self, name=name)
        self.data=queue
    def run(self):
        for i in range(5):
            print("生产者%s将产品%d加入队列!" % (self.getName(), i))
            self.data.put(i)
            time.sleep(random.random())
        print("生产者%s完成!" % self.getName())

#消费者类
class Consumer(threading.Thread):
    def __init__(self,name,queue):
        threading.Thread.__init__(self,name=name)
        self.data=queue
    def run(self):
        for i in range(5):
            val = self.data.get()
            print("消费者%s将产品%d从队列中取出!" % (self.getName(),val))
            time.sleep(random.random())
        print("消费者%s完成!" % self.getName())

if __name__ == '__main__':
    print('-----主线程开始-----')
    queue = Queue()        # 实例化队列
    producer = Producer('Producer',queue)   # 实例化线程Producer，并传入队列作为参数
    consumer = Consumer('Consumer',queue)   # 实例化线程Consumer，并传入队列作为参数
    producer.start()    # 启动线程Producer
    consumer.start()    # 启动线程Consumer
    producer.join()     # 等待线程Producer结束
    consumer.join()     # 等待线程Consumer结束
    print('-----主线程结束-----')