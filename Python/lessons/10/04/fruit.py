
class Fruit:  # 定义水果类（基类）
    color = "绿色"    # 定义类属性
    def harvest(self, color):
        print("水果是：" + color + "的！")  # 输出的是形式参数color
        print("水果已经收获……")
        print("水果原来是：" + Fruit.color + "的！");  # 输出的是类属性color


class Apple(Fruit):  # 定义苹果类（派生类)
    color = "红色"
    def __init__(self):
        print("我是苹果")

class Orange(Fruit):  # 定义橘子类（派生类)
    color = "橙色"
    def __init__(self):
        print("\n我是橘子")
        
     # 重写harvest()方法的代码
##    def harvest(self,color):  
##        print("橘子是："+color+"的！")           # 输出的是形式参数color
##        print("橘子已经收获……")
##        print("橘子原来是："+Fruit.color+"的！");   # 输出的是类属性color


apple = Apple()  # 创建类的实例（苹果）
apple.harvest(apple.color)  # 调用基类的harvest()方法
orange = Orange()  # 创建类的实例（橘子）
orange.harvest(orange.color)  # 调用基类的harvest()方法

