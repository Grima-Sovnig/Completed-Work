year= int (input("Enter Year"))

if ((year% 400 == 0) or ((year%4 == 0)) and (year%100 != 0)):
   print ("%d is a Leap Year" %year)

else:
  print ("%d is not a Leap Year" %year)