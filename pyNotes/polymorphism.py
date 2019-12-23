
class People:
	def __init__(self, name:str, surname:str, idno:int):
		""" Default people attributes """
		self.name = name
		self.surname = surname
		self.idno = idno

""" Polymorphism"""
class NotWorking(People):
	""" People inheritance, all attributes include """
	pass

class Working(People):
	""" People inheritance, all attributes include """
	def __init__(self, name:str, surname:str, idno:int, compno:int):
		#Override
		People.__init__(self, name, surname, idno)
		self.compno = compno

""" Polymorphism """
class Engineer(Working):
	""" Working inheritance, all attributes include """
	def __init__(self, name:str, surname:str, idno:int, compno:int, attributes:tuple):
		#Override
		Working.__init__(self, name, surname, idno, compno)
		self.attributes = attributes

class Accountant(Working):
	""" Working inheritance, all attributes include """
	def __init__(self, name:str, surname:str, idno:int, compno:int, usageApp:tuple):
		#Override 
		Working.__init__(self, name, surname, idno, compno)
		self.usageApp = usageApp



x = Engineer("Sergen", "------", 444, 44, ("ML Engineer"))
print(x.name, x.surname, x.idno, x.compno, x.attributes) 