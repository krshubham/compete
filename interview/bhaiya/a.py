class UpsideDownInt:
  def __init__(self,integer):
    self.__integer = integer
  def __add__(self,anotherInteger):
    return self.__integer - anotherInteger.__integer
  def __sub__(self,anotherInteger):
    return self.__integer + anotherInteger.__integer

a = UpsideDownInt(4)
b = UpsideDownInt(2)
print(a+b)
print(a-b)
