year = 2020   # 年份
result = "是闰年" if (year%4==0 and year % 100 !=0) or (year%100 == 0) else "不是闰年"
print("\n"+str(year) + "年" + result + "!")  # 输出结果

