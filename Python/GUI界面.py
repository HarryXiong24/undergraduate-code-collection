import wx
class MyFrame(wx.Frame):
    def __init__(self,parent,id):
        wx.Frame.__init__(self,parent,id,title="登录界面",pos=(200,200),size=(400,300))
        panel=wx.Panel(self)    #创建画板
        self.title=wx.StaticText(panel,label="请输入用户名和密码",pos=(140,20))
        self.label_user=wx.StaticText(panel,label="用户名",pos=(50,50))
        self.text_user=wx.TextCtrl(panel,pos=(100,50),size=(235,25),style=wx.TE_LEFT)





if __name__=='__main__':
    app=wx.App()
    frame=MyFrame(parent=None,id=-1)
    frame.Show()
    app.MainLoop()
    






