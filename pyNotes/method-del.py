""" __del__ method """

class Book:
	def __init__(self, author:str, name:str, length:int):
		#encapsulation
		self.__author = author
		self.__name = name
		self.__length = length

	def getAuthor(self):
		return self.__author
	def getName(self):
		return self.__name
	def getLenght(self):
		return self.__length

	def __del__(self):
		print("{} deleted" .format(self.__name))

x = Book("Veronica Roth", "Divergent", 300)

del x
