# -*- coding:utf-8 -*-
from multiprocessing import Process
import time
import os

#继承Process类
class SubProcess(Process):
    # 由于Process类本身也有__init__初识化方法，这个子类相当于重写了父类的这个方法
    def __init__(self,interval,name=''):
        Process.__init__(self)      # 调用Process父类的初始化方法
        self.interval = interval    # 接收参数interval
        if name:                    # 判断传递的参数name是否存在
            self.name = name        # 如果传递参数name,则为子进程创建name属性，否则使用默认属性
    #重写了Process类的run()方法
    def run(self):
        print("子进程(%s) 开始执行，父进程为（%s）"%(os.getpid(),os.getppid()))
        t_start = time.time()
        time.sleep(self.interval)
        t_stop = time.time()
        print("子进程(%s)执行结束，耗时%0.2f秒"%(os.getpid(),t_stop-t_start))

if __name__=="__main__":
    print("------父进程开始执行-------")
    print("父进程PID：%s" % os.getpid())                  # 输出当前程序的ID
    p1 = SubProcess(interval=1,name='mrsoft')
    p2 = SubProcess(interval=2)
    #对一个不包含target属性的Process类执行start()方法，就会运行这个类中的run()方法，所以这里会执行p1.run()
    p1.start()  # 启动进程p1
    p2.start()  # 启动进程p2
    # 输出p1和p2进程的执行状态，如果真正进行，返回True,否则返回False
    print("p1.is_alive=%s"%p1.is_alive())
    print("p2.is_alive=%s"%p2.is_alive())
    #输出p1和p2进程的别名和pid
    print("p1.name=%s"%p1.name)
    print("p1.pid=%s"%p1.pid)
    print("p2.name=%s"%p2.name)
    print("p2.pid=%s"%p2.pid)
    print("------等待子进程-------")
    p1.join() # 等待p1进程结束
    p2.join() # 等待p2进程结束
    print("------父进程执行结束-------")