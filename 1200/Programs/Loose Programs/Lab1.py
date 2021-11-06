# Gabriel Snider (CSC 1200 002) this program takes a number the user inputs and converts it to binary.
b=""
num=int(input("Enter a Number here:"))
while(num!=0):
  b= str (num % 2) + b
  num = num // 2
  print (b)
