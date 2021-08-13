class TVshow:   # 定义电视节目类
    list_film = ["战狼2","红海行动","西游记女儿国","熊出没·变形记"]
    def __init__(self,show):
        self.__show = show
    @property                          # 将方法转换为属性
    def show(self):                    # 定义show()方法
        return self.__show             # 返回私有属性的值
    @show.setter    # 设置setter方法，让属性可修改
    def show(self,value):
        if value in TVshow.list_film:   # 判断值是否在列表中
            self.__show = "您选择了《" + value + "》，稍后将播放"   # 返回修改的值
        else:
            self.__show = "您点播的电影不存在"

tvshow = TVshow("战狼2")   # 创建类的实例
print("正在播放：《",tvshow.show,"》")            # 获取属性值
print("您可以从",tvshow.list_film,"中选择要点播放的电影")
tvshow.show = "红海行动"    # 修改属性值
print(tvshow.show)          # 获取属性值
