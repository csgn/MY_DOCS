""" __len__ method """

class Book:
	def __init__(self, author:str, name:str, length:int):
		#encapsulation
		self.__author = author
		self.__name = name
		self.__lenght = length

	def getAuthor(self):
		return self.__author
	def getName(self):
		return self.__name
	def getLenght(self):
		return self.__length

	def __len__(self):
		return self.__length

x = Book("Veronica Roth", "Divergent", 300)

print(len(x))
