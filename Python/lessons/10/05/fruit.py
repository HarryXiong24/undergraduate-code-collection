class Fruit:  # 定义水果类（基类）
    def __init__(self,color = "绿色"):
        Fruit.color = color      # 定义类属性
    def harvest(self, color):
        print("水果是：" + self.color + "的！")  # 输出的是形式参数color
        print("水果已经收获……")
        print("水果原来是：" + Fruit.color + "的！");  # 输出的是类属性color


class Apple(Fruit):  # 定义苹果类（派生类)
    color = "红色"

    def __init__(self):
        print("我是苹果")
        super().__init__()

class Aapodilla(Fruit):  # 定义人参果类（派生类)
    def __init__(self,color):
        print("\n我是人参果")
        super().__init__(color)
        
     # 重写harvest()方法的代码
    def harvest(self,color):  
        print("人参果是："+color+"的！")           # 输出的是形式参数color
        print("人参果已经收获……")
        print("人参果原来是："+Fruit.color+"的！");   # 输出的是类属性color

apple = Apple()  # 创建类的实例（苹果）
apple.harvest(apple.color)  # 调用基类的harvest()方法

sapodilla = Aapodilla("白色") # 创建类的实例（人参果）
sapodilla.harvest("金黄色带紫色条纹")  # 调用基类的harvest()方法




