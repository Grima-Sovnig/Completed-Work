import sys
import socket

if sys.argv[1] == '-s' and sys.argv[3] == '-p' and sys.argv[5] == '-l':
    s = socket.socket(type=socket.SOCK_STREAM)
    logFile = str(sys.argv[6])
    serverIP = str(sys.argv[2])
    port = int(sys.argv[4])
    
    
    try:
        s.connect((serverIP, port))
        print("Connection Sucessful")
    except:
        print("Connection Failed")
        exit()
    
    file = open(logFile, 'a')
    userMessage = input("Input your message for the server: ")
    s.send(userMessage.encode())
    serverMessage = s.recv(8192).decode()
    print("Here was the server's response: ", serverMessage)
    file.write(serverMessage)
    
    s.shutdown(1)