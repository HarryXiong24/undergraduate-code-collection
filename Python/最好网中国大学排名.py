import requests
from bs4 import BeautifulSoup
import bs4

def getHTML(url,kv):
    try:
        r=requests.get(url,headers=kv,timeout=30)
        r.raise_for_status()
        r.encoding=r.apparent_encoding
        return r.text
    except:
        return "Error!"
        
def findHTML(demo,ulist):
    soup=BeautifulSoup(demo,"html.parser")
    for tr in soup.find('tbody').children:
        if isinstance(tr,bs4.element.Tag):
            tds=tr.find_all("td")
            ulist.append([tds[0].string,tds[1].string,tds[2].string,tds[3].string])    
    
def printHTML(ulist,num):
    tplt="{0:^10}\t{1:{3}^10}\t{2:^10}\t"
    print(tplt.format("排名","名称","省市",chr(12288)),"\n")
    for i in range(num):
        u=ulist[i]
        print(tplt.format(u[0],u[1],u[2],chr(12288)))
        

def main():
    kv={"user-agent":"chrome/10.0"}               
    url="http://www.zuihaodaxue.cn/zuihaodaxuepaiming2018.html"
    uinfo=[]
    demo=getHTML(url,kv)
    findHTML(demo,uinfo)
    printHTML(uinfo,100)


main()
    
    
