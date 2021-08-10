class Student:
  
  def __init__(self, name, age, score):
    self.name = name
    self.age = age
    self.score = score

  def get_name(self):
    return self.name

  def get_age(self):
    return self.age

  def get_course(self): 
    self.score.sort()
    return self.score[-1]

stu = Student('ZhangMing',20,[69,88,100,67])

print(stu.get_course())