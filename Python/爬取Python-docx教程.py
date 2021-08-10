import requests
from bs4 import BeautifulSoup
import bs4


r=requests.get("https://www.cnblogs.com/rencm/p/6285304.html")
r.encoding=r.apparent_encoding
html=r.text

soup=BeautifulSoup(html,"html5lib")
text1=soup.find_all("p")
k=0
with open('python-docx使用方法.text','w') as f:
	for k in range(len(text1)):
		text2=text1[k].text+'\n'
		k+=1
		try:
			f.write(text2)
			print(text2)
		except:
			pass

f.close()
