import math
class distance:
    def __init__(self,x=0,y=0):
        self.move(x,y)
    def move(self,x,y):
        self.x=x
        self.y=y
    def reset(self):
        self.move(0,0)
    def jisuan(self,point):
        return math.sqrt((self.x-point.x)**2+(self.y-point.y)**2)

p0=distance()
p1=distance()
p2=distance()

p1.move(3,4)
p2.move(6,8)
print(p1.jisuan(p0))
print(p2.jisuan(p1))
        
