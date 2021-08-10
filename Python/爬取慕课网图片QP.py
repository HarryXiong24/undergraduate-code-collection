import requests
import bs4
from bs4 import BeautifulSoup
import re
import urllib


url="https://www.imooc.com/course/list?c=python"
try:
    r=requests.get(url,timeout=30)
    r.raise_for_status()
    r.encoding=r.apparent_encoding
    html=r.text
except:
    print("Error!")


soup=BeautifulSoup(html,"html.parser")
tit=soup.find_all('img')
i=1
for k in range(3,len(tit)):
	src=tit[k]['src']
	print(src)
	url='https:'+src
	urllib.request.urlretrieve(url,'img'+str(i)+'.jpg')
	i+=1








	





# i=1
# for url in tit1:
# 	img=bytes(url,'utf-8')
# 	with open(str(i)+'.jpg','wb') as f:
# 		f.write(img)
# 		i=i+1
# 	f.close()