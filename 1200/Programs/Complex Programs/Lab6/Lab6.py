# Gabriel Snider, CSC-1200-002, Travis Brumment. This program takes in a file and either encrypts or decrypts the file based of the users option.
# The user will then be warned based of their choice about the file being overwritten with the encrypted or decrypted data.
##
# The getInput() function takes in the file and turns the content into a list. If the file cannot be found it will tell the user the file cannot be found.
def getInput():
    try:
        filename=open(input("Enter Desired File to Open:"),"r").readlines()
        return filename
    except IOError:
        raise IOError("File is not found")
# The EncryptFile() function takes in the data from the file and encrypts the data with the chr, and ord functions in python.
# The data that was taken in is presented in list form.
def EncryptFile(filename):
    EnewLst=[]
    for i in range(0,len(filename), 1):
        line= ""
        for j in range(0, len(filename[i]),1):
            line += chr(ord(filename[i][j])+10)

        EnewLst.append(line)
    return wFile(EnewLst)
#THe DecryptFile() function does the same thing as the encrypt function except the offset is the opposite of the encryption one. So instead of +10, its -10.
def DecryptFile(filename):
    DnewLst=[]
    for i in range(0,len(filename),1):
        line= ""
        for j in range(0,len(filename[i]),1):
            line += chr(ord(filename[i][j])-10)

        DnewLst.append(line)
    return wFile(DnewLst)
#The wFile() function takes the encrypted or decrypted data and writes it the file name given by the user. It warns the user that they will overwrite the file with either the encrypted or decrypted data. After a action is done it allows the user to go back to them menu.
def wFile(EncryptFile):
    print("!WARNING!")
    print("Your file about to be OVERWRITTEN!")
    userFile= input("Enter Your Filename:")

    Filecontents=open(userFile,"w+")

    for things in range(0, len(EncryptFile)):
        Filecontents.write(EncryptFile[things])
    Filecontents.close()
    decision=input("Type M, to go back to menu.")
    if decision=="M":
        menu()
    else:
        print("Invalid Character Entered, Type M to go to Menu.")

        
#The def menu() takes in the user input of what they want to do. They are presented with the options Encrypt or Decrypt.
#If the user inputs something that isn't a choice, the program will tell them it was a invalid selection, and they should try again.
def menu():
    filename=getInput()
    choice=1
    while choice !="-1":
        print("Welcome to the Encrypt or Decrypt Tool!")
        print("1. Encrypt contents of the File")
        print("2. Decrypt contents of the File")
        choice=input("Make your selection:")
        if choice=="1":
            EncryptFile(filename)
        elif choice=="2":
            DecryptFile(filename)
        else:
            print("Invalid Selection Made, Please try again.")


menu()


