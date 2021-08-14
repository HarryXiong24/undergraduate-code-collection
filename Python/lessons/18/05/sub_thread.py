# -*- coding: utf-8 -*-
import threading
import time
class SubThread(threading.Thread):
    def run(self):
        for i in range(3):
            time.sleep(1)
            msg = "子线程"+self.name+'执行，i='+str(i) #name属性中保存的是当前线程的名字
            print(msg)
if __name__ == '__main__':
    print('-----主线程开始-----')
    t1 = SubThread() # 创建子线程t1
    t2 = SubThread() # 创建子线程t2
    t1.start()      # 启动子线程t1
    t2.start()      # 启动子线程t2
    t1.join()       # 等待子线程t1
    t2.join()       # 等待子线程t2
    print('-----主线程结束-----')