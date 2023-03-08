import sys
import socket




#We will start by reading in the command line arguments and sanity checking them.

if sys.argv[1] == '-s' and sys.argv[3] == '-p' and sys.argv[5] == '-l':
    s = socket.socket(type=socket.SOCK_STREAM)  #Initialize the socket
    logFile = str(sys.argv[6]) #Pull the log file name from command line.
    serverIP = str(sys.argv[2]) #Pull Server IP from command line.
    port = int(sys.argv[4]) #Pull Port from command line.

    print(serverIP)
    print(port)
    try: #Attempts to connect to the provided server.
        s.connect((serverIP, port))
        print("Sucessfully Connected")
    except: #If connection fails we get a message.
        print("Connection Failed: Check provided IP and Port.")
        exit()
    #Open file that will be used as the log file.
    file = open(logFile, 'a')
    #Allow the user to input their desired message.
    userMessage = input("What is the message that you would like to send to the server?")
    #Tells the socket to send the message to the server.
    s.send(userMessage.encode())
    #serverMessage is set to the socket receiving data. Whatever this data is, is our message from the server.
    serverMessage = s.recv(8192).decode()
    #Printing the server  response just to let the user see it.
    print("The Server's Response was: ", serverMessage)
    #Finally store the server's message in the log file.
    file.write(serverMessage)
    
    #Gracefully closing the socket.
    s.shutdown(1)
    
    
    
    
    
    
else:
    print("Please Try Again! Use the Provided Format: client -s 192.168.2.1 -p 6543 -l LOGFILE")






    
