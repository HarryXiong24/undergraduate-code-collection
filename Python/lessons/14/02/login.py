# -*- coding:utf-8 -*-
import wx
class MyFrame(wx.Frame):
    def __init__(self,parent,id):
        wx.Frame.__init__(self, parent,id, title="创建TextCtrl类",size=(400, 300))
        #创建面板
        panel = wx.Panel(self) 
        # 创建文本和输入框
        self.title = wx.StaticText(panel ,label="请输入用户名和密码",pos=(140,20))
        self.label_user = wx.StaticText(panel,label="用户名:",pos=(50,50) )
        self.text_user = wx.TextCtrl(panel,pos=(100,50),size=(235,25),style=wx.TE_LEFT)
        self.label_pwd = wx.StaticText(panel,pos=(50,90),label="密   码:")
        self.text_password = wx.TextCtrl(panel,pos=(100,90),size=(235,25),style=wx.TE_PASSWORD)

if __name__ == '__main__':        
    app = wx.App()                      # 初始化应用
    frame = MyFrame(parent=None,id=-1)  # 实例MyFrame类，并传递参数    
    frame.Show()                        # 显示窗口
    app.MainLoop()                      # 调用主循环方法
