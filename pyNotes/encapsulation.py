#!/usr/bin/env python3

class Car:
	def __init__(self):
		self.__velocity = 0 # unreach

	def setVelocity(self, velocity):
		self.__velocity = velocity

	def getVelocity(self):
		return self.__velocity

x = Car()
# print(x.__velocity) not working 

print(x.getVelocity()) 

x.setVelocity(20)  

print(x.getVelocity())
