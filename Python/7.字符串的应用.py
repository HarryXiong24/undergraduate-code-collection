str1="I am a dreamer"
str2="My dream will come true"

str3=str1+'\t'+str2               #拼接字符串
str11=str1.encode("gbk","strict")      #编码字符串
str4=str1[7:15:1]               #截取字符串(注意是从0开始计算)
str5=str1.split(" ")            #分割字符串

list1=["I","am","a","dreamer"] 
str6=" ".join(list1)            #合并字符串

print(str1.lower())
print(str2.upper())
print(str3)
print(str11)
print(str4)
print(str5)
print(str6)

print(str1.count("a"))
print(str1.find("dreamer"))
print(str1.startswith("d",7,15))


