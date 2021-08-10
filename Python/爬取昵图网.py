import requests
from bs4 import BeautifulSoup
import urllib

url='http://soso.nipic.com/'
kv={'user-agent':'chrome/10.0'}
try:
	r=requests.get(url,headers=kv)
	r.raise_for_status()
	r.encoding=r.apparent_encoding
	html=r.text
except:
	print("Error!")

soup=BeautifulSoup(html,"html.parser")
imgurl=soup.find_all("img")
list(imgurl)
for i in range(1,4):
	del imgurl[0] 
print(imgurl)
try:
	for i in range(0,len(imgurl)):
			img=imgurl[i]['data-original']
			urllib.request.urlretrieve(img,str(i)+'.jpg')
			i+=1
except:
	print("Error!")
