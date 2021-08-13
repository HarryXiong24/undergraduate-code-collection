name = ['绮梦','冷伊一','香凝','黛兰']        # 作为键的列表
sign = ['水瓶','射手','双鱼','双子']  # 作为值的列表
dictionary = {i:j+'座' for i,j in zip(name,sign)}            # 使用列表推导式生成字典
print(dictionary)                              # 输出转换后字典
