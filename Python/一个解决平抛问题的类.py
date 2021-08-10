#求解平抛运动的问题，其中参数高度h、初速度v0,求末速度v、下落时间t、水平位移x
#默认重力加速度g=10，单位均为国际标准单位
import math
class pingpao:
    def __init__(self,h=0,v0=0,v=0,t=0,x=0):
        self.h=h
        self.v0=v0
        self.v=v
        self.t=t
        self.x=x
        
        self.g=10
        self.vy=0
        
    def res_t(self):
        self.t=math.sqrt(2*self.h/self.g)
        return self.t

    def res_x(self):
        self.x=self.v0*self.t
        return self.x

    def res_v(self):
        self.vy=self.g*self.t 
        self.v=math.sqrt(self.v**2+self.v0**2)
        return self.v
         
eg1=pingpao(1,1)
print(eg1.res_t())
print(eg1.res_x())
print(eg1.res_v())



