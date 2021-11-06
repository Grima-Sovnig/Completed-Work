# Gabriel Snider, Lab 3 Binary Menu, October 3rd, 2019. This program creates a menu that gives the user the option to chose whether they want to convert something into a binary number, or convert a binary number to a decimal. The user will also have the option to reverse a string.
# This first def makes a menu for the user to choose what they wish to do, based on their decisions the opt variable decides what to do next.
def menu():
  while(True):
    print ("Welcome, what can this program do for you?.")
    print ("\t 1. Convert Decimal to Binary")
    print ("\t 2. Convert Binary to Decimal")
    print ("\t 3. Quit")
    opt=input("Input a Choice or Press Q to Exit.")
    if(int(opt)==1):
      Base2()
    elif(int(opt)==2):
      Base10()
    elif(int(opt)==3):
      break;
    else:
      print("Invalid Choice!\n")


#Name: Base2, Input: num, Output: b, Description: This takes a number that the user enters and converts it to binary and returns that to the user. 
def Base2():
  b=""
  num=int(input("Enter a Number here:"))
  while(num!=0):
    b= str (num % 2) + b
    num = num // 2
  print (b)
#Name: Reverse, Input:string s, Output:String r, Description: This takes a string as input and reverses that string and then returns it as the output.
def reverse(s):
  r=""
  for i in s:
    r=i+r
  return r
#Name: Base10, Input:yeet=binary number Output: sum, Description: This function takes a number and uses the reverse function then converts it to base10 or a decimal number.
def Base10():
  print ("Please enter a Binary Number:")
  yeet=list(input("Binary Number Here:"))
  sum=0
  yeet=reverse(yeet)
  for i in range(0,len(yeet)):
      sum+=(int(yeet[i])*(2**i))
  print(sum)



menu()