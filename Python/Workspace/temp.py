import random

def judge():
  print('智坤傻吗')
  number = random.randint(0, 9)
  if number > 4:
    print('他不算傻逼')
  else:
    print('绝对是傻逼')


class Animal:


  def __init__(self, name, age):
    self._name = name
    self._age = age

  def set_name(self, name):
    self._name = name

  def get_name(self):
    return self._name

  # 类成员方法需要传入代表本类的cls参数, 类成员方法无法访问实例变量但是可以访问类变量
  # @classmethod
  

  # 静态方法不需要传入self参数, 静态方法是无妨访问实例变量和类变量的
  # @staticmethod


if __name__ == "__main__":

  animal = Animal('熊浩玮', 20)

  print(animal.get_name())

  animal.set_name('熊浩玮帅哥')

  print(animal.get_name())

