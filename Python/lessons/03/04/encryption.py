password = 87654321   # 密码
key = 7 # 加密参数
print("\n原密码：",password)  # 输出原密码
password = password << key  # 将原密码左移，生成新的数字
print("\n加密后：",password)  # 输出加密后的密码
password = password >> key  # 将新密码右移，还原密码
print("\n解密后：",password)  # 输出解密后的密码

