# Gabriel Snider (CSC 1200-002)
# This program is a final grade calculator based on 6 quizzes, 4 test grades, 6 project grades, and a participation grade.
sname= input("Enter Student Name:")
print ("Hello", sname, "Enter your Grades here to receive final grade.")
qg=int(input("Enter Total Possible Quiz Grade:"))
qw=float(input("Enter Quiz Weight in Decimal Form:"))
q1=int(input("Enter Grade for Quiz 1:"))
q2=int(input("Enter Grade for Quiz 2:"))
q3=int(input("Enter Grade for Quiz 3:"))
q4=int(input("Enter Grade for Quiz 4:"))
q5=int(input("Enter Grade for Quiz 5:"))
q6=int(input("Enter Grade for Quiz 6:"))
pg=int(input("Enter Total Possible Participation Grade:"))
pw=float(input("Enter Participation Grade Weight in Decimal Form:"))
pg1=int(input("Enter Participation Grade:"))
pjg=int(input("Enter Total Possible Project Grade:"))
pjw=float(input("Enter Project Grade Weight in Decimal Form:"))
pj1=int(input("Enter First Project Grade:"))
pj2=int(input("Enter Second Project Grade:"))
pj3=int(input("Enter Third Project Grade:"))
pj4=int(input("Enter Fourth Project Grade:"))
pj5=int(input("Enter Fifth Project Grade:"))
pj6=int(input("Enter Sixth Project Grade:"))
tg=int(input("Enter Total Possible Test Grade:"))
tw=float(input("Enter Test Weight in Decimal Form:"))
t1=int(input("Enter First Test Grade:"))
t2=int(input("Enter Second Test Grade:"))
t3=int(input("Enter Third Test Grade:"))
t4=int(input("Enter Fourth Test Grade:"))

#I used a letter to symbolize what each variable is. Q=Quizzes, P=Participation, PJ=Project,and T= Test. I then used a constant variable for each type of input for these sections. G=Total Possible Grade, W=Grade Weight, then numbers 1-6=Grades correspending to assignments 1-6.

print ("Your Grades will be posted below:")
oqg=(q1+q2+q3+q4+q5+q6)
sqg=(oqg/qg)
fqg=(sqg*qw)*100
print ("Overall Quiz Grade:",fqg)
fpg=(pg1*pw)
print ("Overall Participation Grade:",fpg)
opjg=(pj1+pj2+pj3+pj4+pj5+pj6)
spjg=(opjg/pjg)
fpjg=(spjg*pjw)*100
print ("Overall Project Grade:",fpjg)
otg=(t1+t2+t3+t4)
stg=(otg/tg)
ftg=(stg*tw)*100
print ("Overall Test Grade:", ftg)

#Above I have done the math to calclate student grades, based on inputs. I then applied the students grade to the weight for each item. I then make the program print the weighted grade to the student.

fg=(ftg+fpjg+fpg+fqg)
print ("Final Grade is:",fg)
#This final variable is for the final grade of all of the previous ones added together. Next will be the if-then statement for the letter grade.

if  float(fg>= 90 and fg<=100):
  print ("Final Grade: A")
elif float(fg>=80 and fg<90):
  print ("Final Grade: B")
elif float(fg>=70 and fg<80):
  print ("Final Grade: C")
elif float(fg>=60 and fg<70):
  print ("Final Grade: D")
elif float(fg<60):
  print ("Final Grade: F")