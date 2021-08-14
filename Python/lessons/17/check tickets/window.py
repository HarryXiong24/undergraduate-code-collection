# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'window4.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!
from PyQt5.QtWidgets import *
from query_request import *
from PyQt5.QtGui import *
import sys
import time

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QPalette, QPixmap, QColor


# result = []  # 保存车次分类后最后的数据


# UI类
class Ui_MainWindow(object):

    # 设置UI的方法
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")  # 设置窗体对象名称
        MainWindow.resize(960, 786)  # 设置窗体大小
        MainWindow.setMinimumSize(QtCore.QSize(960, 786))  # 主窗体最小值
        MainWindow.setMaximumSize(QtCore.QSize(960, 786))  # 主窗体最大值
        self.centralwidget = QtWidgets.QWidget(MainWindow)  # 主窗体的widget控件
        self.centralwidget.setObjectName("centralwidget")  # 设置对象名称

        # 通过label控件显示顶部图片
        self.label_title_img = QtWidgets.QLabel(self.centralwidget)
        self.label_title_img.setGeometry(QtCore.QRect(0, 0, 960, 141))
        self.label_title_img.setObjectName("label_title_img")
        title_img = QPixmap('img/bg1.png')  # 打开顶部位图
        self.label_title_img.setPixmap(title_img)  # 设置调色板

        # 查询部分的widget
        self.widget_query = QtWidgets.QWidget(self.centralwidget)
        self.widget_query.setGeometry(QtCore.QRect(0, 141, 960, 80))
        self.widget_query.setObjectName("widget_query")
        # 开启自动填充背景
        self.widget_query.setAutoFillBackground(True)
        palette = QPalette()  # 调色板类
        palette.setBrush(QPalette.Background, QtGui.QBrush(QtGui.QPixmap('img/bg2.png')))  # 设置背景图片
        self.widget_query.setPalette(palette)  # 为控件设置对应的调色板即可

        # 出发地与对应的编辑框控件
        self.label = QtWidgets.QLabel(self.widget_query)
        self.label.setGeometry(QtCore.QRect(30, 30, 54, 12))
        self.label.setObjectName("label")
        self.textEdit = QtWidgets.QTextEdit(self.widget_query)
        self.textEdit.setGeometry(QtCore.QRect(80, 20, 104, 31))
        font = QtGui.QFont()  # 创建QFont()对象
        font.setPointSize(13)  # 设置编辑框字体大小的值
        self.textEdit.setFont(font)  # 设置编辑框字体
        self.textEdit.setObjectName("textEdit")  # 出发地对应编辑框对象名称

        # 目的地与对应的编辑框
        self.label_2 = QtWidgets.QLabel(self.widget_query)
        self.label_2.setGeometry(QtCore.QRect(220, 30, 54, 12))
        self.label_2.setObjectName("label_2")
        self.textEdit_2 = QtWidgets.QTextEdit(self.widget_query)
        self.textEdit_2.setGeometry(QtCore.QRect(270, 20, 104, 31))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.textEdit_2.setFont(font)
        self.textEdit_2.setObjectName("textEdit_2")

        # 出发日与有对应的编辑框
        self.label_3 = QtWidgets.QLabel(self.widget_query)
        self.label_3.setGeometry(QtCore.QRect(410, 30, 54, 12))
        self.label_3.setObjectName("label_3")
        self.textEdit_3 = QtWidgets.QTextEdit(self.widget_query)
        self.textEdit_3.setGeometry(QtCore.QRect(460, 20, 104, 31))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.textEdit_3.setFont(font)
        self.textEdit_3.setObjectName("textEdit_3")

        # 查询按钮
        self.pushButton = QtWidgets.QPushButton(self.widget_query)
        self.pushButton.setGeometry(QtCore.QRect(610, 20, 91, 31))
        self.pushButton.setObjectName("pushButton")

        # 选择车次类型的widget
        self.widget_checkBox = QtWidgets.QWidget(self.centralwidget)
        self.widget_checkBox.setGeometry(QtCore.QRect(0, 220, 961, 35))
        self.widget_checkBox.setAutoFillBackground(False)
        self.widget_checkBox.setObjectName("widget_checkBox")
        # 开启自动填充背景
        self.widget_checkBox.setAutoFillBackground(True)
        palette = QPalette()  # 调色板类
        palette.setBrush(QPalette.Background, QtGui.QBrush(QtGui.QPixmap('img/bg3.png')))  # 设置背景图片
        self.widget_checkBox.setPalette(palette)  # 设置调色板控件对应的方法即可

        # 显示车次类型文字
        self.label_type = QtWidgets.QLabel(self.widget_checkBox)
        self.label_type.setGeometry(QtCore.QRect(30, 9, 65, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.label_type.setFont(font)
        self.label_type.setObjectName("label_type")

        # 选择高铁
        self.checkBox_G = QtWidgets.QCheckBox(self.widget_checkBox)
        self.checkBox_G.setGeometry(QtCore.QRect(100, 9, 70, 17))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.checkBox_G.setFont(font)
        self.checkBox_G.setObjectName("checkBox_GC")

        # 选择动车
        self.checkBox_D = QtWidgets.QCheckBox(self.widget_checkBox)
        self.checkBox_D.setGeometry(QtCore.QRect(258, 9, 63, 17))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.checkBox_D.setFont(font)
        self.checkBox_D.setObjectName("checkBox_D")
        # 选择直达
        self.checkBox_Z = QtWidgets.QCheckBox(self.widget_checkBox)
        self.checkBox_Z.setGeometry(QtCore.QRect(415, 9, 63, 17))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.checkBox_Z.setFont(font)
        self.checkBox_Z.setObjectName("checkBox_Z")
        # 选择特快
        self.checkBox_T = QtWidgets.QCheckBox(self.widget_checkBox)
        self.checkBox_T.setGeometry(QtCore.QRect(572, 9, 63, 17))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.checkBox_T.setFont(font)
        self.checkBox_T.setObjectName("checkBox_T")
        # 选择快速
        self.checkBox_K = QtWidgets.QCheckBox(self.widget_checkBox)
        self.checkBox_K.setGeometry(QtCore.QRect(730, 9, 63, 17))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.checkBox_K.setFont(font)
        self.checkBox_K.setObjectName("checkBox_K")

        # 通过label控件显示火车信息图片
        self.label_train_img = QtWidgets.QLabel(self.centralwidget)
        self.label_train_img.setGeometry(QtCore.QRect(0, 256, 960, 62))
        self.label_train_img.setObjectName("label_train_img")
        train_img = QPixmap('img/bg4.png')  # 打开火车信息位图
        self.label_train_img.setPixmap(train_img)  # 设置调色板
        # 显示车次信息的列表
        self.tableView = QtWidgets.QTableView(self.centralwidget)
        self.tableView.setGeometry(QtCore.QRect(0, 320, 960, 440))
        self.tableView.setObjectName("tableView")
        self.model = QStandardItemModel();  # 创建存储数据的模式
        # 根据空间自动改变列宽度并且不可修改列宽度
        self.tableView.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        # 设置表头不可见
        self.tableView.horizontalHeader().setVisible(False)
        # 纵向表头不可见
        self.tableView.verticalHeader().setVisible(False)
        # 设置表格内容文字大小
        font = QtGui.QFont()
        font.setPointSize(10)
        self.tableView.setFont(font)
        # 设置表格内容不可编辑
        self.tableView.setEditTriggers(QAbstractItemView.NoEditTriggers)
        # 垂直滚动条始终开启
        self.tableView.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        # 主窗体设置主Widget
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)  # 调用retranslateUi方法显示窗体文字
        QtCore.QMetaObject.connectSlotsByName(MainWindow)  # 关联信号槽

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "快手查票"))
        self.checkBox_T.setText(_translate("MainWindow", "T-特快"))
        self.checkBox_K.setText(_translate("MainWindow", "K-快速"))
        self.checkBox_Z.setText(_translate("MainWindow", "Z-直达"))
        self.checkBox_D.setText(_translate("MainWindow", "D-动车"))
        self.checkBox_G.setText(_translate("MainWindow", "GC-高铁"))
        self.label_type.setText(_translate("MainWindow", "车次类型："))
        self.label.setText(_translate("MainWindow", "出发地："))
        self.label_2.setText(_translate("MainWindow", "目的地："))
        self.label_3.setText(_translate("MainWindow", "出发日："))
        self.pushButton.setText(_translate("MainWindow", "查询"))

        self.textEdit_3.setText(get_time())  # 出发日显示当天日期
        self.pushButton.clicked.connect(self.on_click)  # 查询按钮指定单击事件的方法
        self.checkBox_G.stateChanged.connect(self.change_G)  # 高铁选中与取消事件
        self.checkBox_D.stateChanged.connect(self.change_D)  # 动车选中与取消事件
        self.checkBox_Z.stateChanged.connect(self.change_Z)  # 直达车选中与取消事件
        self.checkBox_T.stateChanged.connect(self.change_T)  # 特快车选中与取消事件
        self.checkBox_K.stateChanged.connect(self.change_K)  # 快车选中与取消事件

    # 查询按钮的单击事件
    def on_click(self):
        get_from = self.textEdit.toPlainText()  # 获取出发地
        get_to = self.textEdit_2.toPlainText()  # 获取到达地
        get_date = self.textEdit_3.toPlainText()  # 获取出发时间
        # 判断车站文件是否存在
        if isStations() == True:
            stations = eval(read())  # 读取所有车站并转换为dic类型
            # 判断所有参数是否为空，出发地、目的地、出发日期
            if get_from != "" and get_to != "" and get_date != "":
                # 判断输入的车站名称是否存在，以及时间格式是否正确
                if get_from in stations and get_to in stations and is_valid_date(get_date):
                    # 获取输入的日期是当前年初到现在一共过了多少天
                    inputYearDay = time.strptime(get_date, "%Y-%m-%d").tm_yday
                    # 获取系统当前日期是当前年初到现在一共过了多少天
                    yearToday = time.localtime(time.time()).tm_yday
                    # 计算时间差，也就是输入的日期减掉系统当前的日期
                    timeDifference = inputYearDay - yearToday
                    # 判断时间差为0时证明是查询当前的查票，
                    # 以及29天以后的车票。12306官方要求只能查询30天以内的车票
                    if timeDifference >= 0 and timeDifference <= 28:
                        from_station = stations[get_from]  # 在所有车站文件中找到对应的参数，出发地
                        to_station = stations[get_to]  # 目的地
                        print(from_station)
                        data = query(get_date, from_station, to_station)  # 发送查询请求,并获取返回的信息
                        if len(data) != 0:  # 判断返回的数据是否为空
                            # 如果不是空的数据就将车票信息显示在表格中
                            self.displayTable(len(data), 16, data)
                        else:
                            self.messageDialog('警告', '没有返回的网络数据！')
                    else:
                        self.messageDialog('警告', '超出查询日期的范围内,'
                                                 '不可查询昨天的车票信息,以及29天以后的车票信息！')
                else:
                    self.messageDialog('警告', '输入的站名不存在,或日期格式不正确！')
            else:
                self.messageDialog('警告', '请填写车站名称！')
        else:
            self.messageDialog('警告', '未下载车站查询文件！')

    # 高铁复选框事件处理
    def change_G(self, state):
        # 选中将高铁信息添加到最后要显示的数据当中
        if state == QtCore.Qt.Checked:
            # 获取高铁信息
            g_vehicle()
            # 通过表格显示该车型数据
            self.displayTable(len(type_data), 16, type_data)
        else:
            # 取消选中状态将移除该数据
            r_g_vehicle()
            self.displayTable(len(type_data), 16, type_data)

    # 动车复选框事件处理
    def change_D(self, state):
        # 选中将动车信息添加到最后要显示的数据当中
        if state == QtCore.Qt.Checked:
            # 获取动车信息
            d_vehicle()
            # 通过表格显示该车型数据
            self.displayTable(len(type_data), 16, type_data)

        else:
            # 取消选中状态将移除该数据
            r_d_vehicle()
            self.displayTable(len(type_data), 16, type_data)

    # 直达复选框事件处理
    def change_Z(self, state):
        # 选中将直达车信息添加到最后要显示的数据当中
        if state == QtCore.Qt.Checked:
            # 获取直达车信息
            z_vehicle()
            self.displayTable(len(type_data), 16, type_data)
        else:
            # 取消选中状态将移除该数据
            r_z_vehicle()
            self.displayTable(len(type_data), 16, type_data)

    # 特快复选框事件处理
    def change_T(self, state):
        # 选中将特快车信息添加到最后要显示的数据当中
        if state == QtCore.Qt.Checked:
            # 获取特快车信息
            t_vehicle()
            self.displayTable(len(type_data), 16, type_data)
        else:
            # 取消选中状态将移除该数据
            r_t_vehicle()
            self.displayTable(len(type_data), 16, type_data)

    # 快速复选框事件处理
    def change_K(self, state):
        # 选中将快车信息添加到最后要显示的数据当中
        if state == QtCore.Qt.Checked:
            # 获取快速车信息
            k_vehicle()
            self.displayTable(len(type_data), 16, type_data)

        else:
            # 取消选中状态将移除该数据
            r_k_vehicle()
            self.displayTable(len(type_data), 16, type_data)

    # 显示消息提示框，参数title为提示框标题文字，message为提示信息
    def messageDialog(self, title, message):
        msg_box = QMessageBox(QMessageBox.Warning, title, message)
        msg_box.exec_()

    # 显示车次信息的表格
    # train参数为共有多少趟列车，该参数作为表格的行。
    # info参数为每趟列车的具体信息，例如有座、无座卧铺等。该参数作为表格的列
    def displayTable(self, train, info, data):
        self.model.clear()
        for row in range(train):
            for column in range(info):
                # 添加表格内容
                item = QStandardItem(data[row][column])
                # 向表格存储模式中添加表格具体信息
                self.model.setItem(row, column, item)
        # 设置表格存储数据的模式
        self.tableView.setModel(self.model)


# 获取系统当前时间并转换请求数据所需要的格式
def get_time():
    # 获得当前时间时间戳
    now = int(time.time())
    # 转换为其它日期格式,如:"%Y-%m-%d %H:%M:%S"
    timeStruct = time.localtime(now)
    strTime = time.strftime("%Y-%m-%d", timeStruct)
    return strTime


def is_valid_date(str):
    '''判断是否是一个有效的日期字符串'''
    try:
        time.strptime(str, "%Y-%m-%d")
        return True
    except:
        return False


def show_MainWindow():
    app = QtWidgets.QApplication(sys.argv)  # 首先必须实例化QApplication类，作为GUI主程序入口
    MainWindow = QtWidgets.QMainWindow()  # 实例化QtWidgets.QMainWindow类，创建自带menu的窗体类型QMainWindow
    ui = Ui_MainWindow()  # 实例UI类
    ui.setupUi(MainWindow)  # 设置窗体UI
    MainWindow.show()  # 显示窗体
    sys.exit(app.exec_())  # 当来自操作系统的分发事件指派调用窗口时，
    # 应用程序开启主循环（mainloop）过程，
    # 当窗口创建完成，需要结束主循环过程，
    # 这时候呼叫sys.exit（）方法来，结束主循环过程退出，
    # 并且释放内存。为什么用app.exec_()而不是app.exec()？
    # 因为exec是python系统默认关键字，为了以示区别，所以写成exec_


if __name__ == "__main__":
    if isStations() == False:  # 判断是否有所有车站的文件，没有就下载，有就直接显示窗体
        getStation()  # 下载所有车站文件
        show_MainWindow()  # 调用显示窗体的方法
    else:
        show_MainWindow()  # 调用显示窗体的方法
