""" __str__ method """

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

	def __str__(self):
		# return <__main__.Book object at 0x005EDBF0>
		# override 
		return self.__author + " " +  self.__name + " " + str(self.__lengtht)

x = Book("Veronica Roth", "Divergent", 300)

print(str(x))
