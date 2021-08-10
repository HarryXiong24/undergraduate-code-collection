import requests
path="D:/abc.jpg"
url="https://i04piccdn.sogoucdn.com/c423106109a102db"
r=requests.get(url)
r.status_code
with open(path,'wb') as f:
    f.write(r.content)
f.close()
