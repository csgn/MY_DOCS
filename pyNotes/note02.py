#!/usr/bin/env python

from datetime import date, datetime

class Book:
	
	def __init__(self, author:str, name:str, issueDate:date, numberOfPages:int):
		self.author = author
		self.name = name
		self.issueDate = issueDate
		self.numberOfPages = NumberOfPages

x = Book("Paulo Coelho", "Alchemist", date(2018, 3, 5), 140)
print(x.author, x.name, x.issueDate, x.numberOfPages)
