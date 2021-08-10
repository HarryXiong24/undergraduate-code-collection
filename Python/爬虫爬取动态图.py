import requests
url="https://123p4.sogoucdn.com/imgu/2019/01/20190109114604_548.gif"
path="D:abc.gif"
kv={'user-agent':'chrome/10.0'}
try:
    r=requests.get(url,headers=kv)
    r.raise_for_status()
    with open(path,'wb') as f:
        f.write(r.content)
    f.close()
except:
    print("爬取失败")
