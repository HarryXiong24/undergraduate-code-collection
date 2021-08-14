import requests
from get_stations import *

'''5-7 目的地 3  车次 6  出发地 8  出发时间 9  到达时间 10 历时 26 无坐 29 硬座
   24 软座 28 硬卧 33 动卧 23 软卧 21 高级软卧 30 二等座 31 一等座 32 商务座特等座
'''
data = []  # 用于保存整理好的车次信息
type_data = []  # 保存车次分类后最后的数据


def query(date, from_station, to_station):
    data.clear()  # 清空数据
    # 查询请求地址
    url = 'https://kyfw.12306.cn/otn/leftTicket/queryO?leftTicketDTO.train_date={}&leftTicketDTO.from_station={}&leftTicketDTO.to_station={}&purpose_codes=ADULT'.format(
        date, from_station, to_station)
    # 发送查询请求
    response = requests.get(url)
    # # 将json数据转换为字典类型，通过键值对取数据
    result = response.json()
    result = result['data']['result']
    # 判断车站文件是否存在
    if isStations() == True:
        stations = eval(read())  # 读取所有车站并转换为dic类型
        if len(result) != 0:  # 判断返回数据是否为空
            for i in result:
                # # 分割数据并添加到列表中
                tmp_list = i.split('|')
                # 因为查询结果中出发站和到达站为站名的缩写字母，所以需要在车站库中找到对应的车站名称
                from_station = list(stations.keys())[list(stations.values()).index(tmp_list[6])]
                to_station = list(stations.keys())[list(stations.values()).index(tmp_list[7])]
                # 创建座位数组，由于返回的座位数据中含有空既“”，所以将空改成--这样好识别
                seat = [tmp_list[3], from_station, to_station, tmp_list[8], tmp_list[9], tmp_list[10]
                    , tmp_list[32], tmp_list[31], tmp_list[30], tmp_list[21]
                    , tmp_list[23], tmp_list[33], tmp_list[28], tmp_list[24], tmp_list[29], tmp_list[26]]
                newSeat = []
                # 循环将座位信息中的空既“”，改成--这样好识别
                for s in seat:
                    if s == "":
                        s = "--"
                    else:
                        s = s
                    newSeat.append(s)  # 保存新的座位信息
                data.append(newSeat)
        return data  # 返回整理好的车次信息

# 获取高铁信息的方法
def g_vehicle():
    if len(data) != 0:
        for g in data:  # 循环所有火车数据
            i = g[0].startswith('G')  # 判断车次首字母是不是高铁
            if i:  # 如果是将该条信息添加到高铁数据中
                type_data.append(g)

#移除高铁信息的方法
def r_g_vehicle():
    if len(data) != 0:
        for g in data:
            i = g[0].startswith('G')
            if i:   #移除高铁信息
                type_data.remove(g)

# 获取动车信息的方法
def d_vehicle():
    if len(data) != 0:
        for d in data:  # 循环所有火车数据
            i = d[0].startswith('D')  # 判断车次首字母是不是动车
            if i == True:  # 如果是将该条信息添加到动车数据中
                type_data.append(d)
# 移除动车信息的方法
def r_d_vehicle():
    if len(data) != 0:
        for d in data:
            i = d[0].startswith('D')
            if i == True:   #移除动车信息
                type_data.remove(d)

# 获取直达车信息的方法
def z_vehicle():
    if len(data) != 0:
        for z in data:  # 循环所有火车数据
            i = z[0].startswith('Z')  # 判断车次首字母是不是直达
            if i == True:  # 如果是将该条信息添加到直达数据中
                type_data.append(z)

# 移除直达车信息的方法
def r_z_vehicle():
    if len(data) != 0:
        for z in data:
            i = z[0].startswith('Z')
            if i == True:  # 移除直达车信息
                type_data.remove(z)




# 获取特快车信息的方法
def t_vehicle():
    if len(data) != 0:
        for t in data:  # 循环所有火车数据
            i = t[0].startswith('T')  # 判断车次首字母是不是特快
            if i == True:  # 如果是将该条信息添加到特快车数据中
                type_data.append(t)
# 移除特快车信息的方法
def r_t_vehicle():
    if len(data) != 0:
        for t in data:
            i = t[0].startswith('T')
            if i == True:  # 移除特快车信息
                type_data.remove(t)

# 获取快速车数据的方法
def k_vehicle():
    if len(data) != 0:
        for k in data:  # 循环所有火车数据
            i = k[0].startswith('K')  # 判断车次首字母是不是快车
            if i == True:  # 如果是将该条信息添加到快车数据中
                type_data.append(k)

# 移除快速车数据的方法
def r_k_vehicle():
    if len(data) != 0:
        for k in data:
            i = k[0].startswith('K')
            if i == True:  # 移除快车信息
                type_data.remove(k)
