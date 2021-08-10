import re
import requests

def getHTML(url):
    try:
        r=requests.get(url,timeout=30)
        r.raise_for_status()
        r.encoding=r.apparent_encoding
        return r.text
    except:
        return "Error!"


def findHTML(html,ulist):
    try:
        n=re.findall(r'alt="',html)
        p=re.findall(r'trace-price="',html)
        for i in range(len(n)):
            name=eval(n[i].split('vivo')[1])
            price=eval(n[i].split('"')[1])
            ulist.append([name,price])
    except:
        print("")

def printHTML(ulist):
    tplt="{:4}\t{:8}\t{:16}"
    print(tplt.format("序号","价格","名称"))
    count=0
    for i in ulist:
        count=count+1
        print(tplt.format(count,i[0],i[1]))


def main():
    url="https://s.taobao.com/search?spm=a230r.1.1998181369.d4919860.5ea650d65pmNsG&ie=utf8&initiative_id=staobaoz_20190110&js=1&imgfile=&q=vivo手机官网&suggest=0_2&_input_charset=utf-8&wq=vivo手机&suggest_query=vivo手机&source=suggest&tab=mall&bcoffset=0&p4ppushleft=%2C44&s=44"
    infolist=[]
    html=getHTML(url)
    findHTML(html,infolist)
    printHTML(infolist)

main()
