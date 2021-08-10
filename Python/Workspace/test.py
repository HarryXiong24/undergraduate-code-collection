number = 0

while True:
  userName = input("请输入用户名: ")
  passWord = input("请输入密码: ")
  number += 1

  if userName == "seven" and passWord == "123": 
    print('登陆成功')
  else: 
    print('登陆失败')
    if number == 3: 
      break

