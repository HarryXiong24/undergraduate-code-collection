s=[i for i in range(10)]
d=dict(zip(s,s))
print(d)

x=eval(input("key:"))
if d.get(x)==None:
        print('不存在')
else:
        print("value is:",d.get(x))
        
