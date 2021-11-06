#CSC 1200-Gabriel Snider. Travis Brumment Lab 4 Restaurant Randomizer. October 8th, 2019. This program intakes restaurant names that a user inputs until the user types quit. The list will then be randomized and print back a number at the index called.

#Here we import random so we can use it later on in a function if we need to.
import random

#This first function getInput() will take restaurant names from the user until they type quit, or Quit. 
#In this function we have the list restaurants which will be filled with names from the restaurant variable that takes a user input. The function also allows for the user to quit out of the program by typing in quit or Quit.

def getInput():
  restaurants=[]
  restaurant=input("Enter Restaurant Name:")
  while restaurant.lower()!= "quit":
    restaurants.append(restaurant)
    restaurant=input("Enter Restaurant Name:")
  return restaurants



#This second function Randomize(lst) takes in the list made in the previous function getInput(). It them generates a random number and prints the lists contents at the given index.

def Randomize(lst):
  index=random.randint(0,len(lst)-1)
  return lst[index]

print(Randomize(getInput()))
