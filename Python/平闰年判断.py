m=int(input("请输入一个年份："))

if m<=0:
   print("输入有误！")
    
if m%400==0 or (m%100!=0 and m%4==0):
   print("输入的年份为闰年")
else:
   print("输入的年份为平年")
   
