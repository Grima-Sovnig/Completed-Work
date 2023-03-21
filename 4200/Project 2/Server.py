import socket
import sys
import struct
import random
import argparse

def serverside(argv=None):
    parser = argparse.ArgumentParser(description="SERVER")
    parser.add_argument('-p', type=int, required=True, help='Port')
    parser.add_argument('-l', type=str, required=True, help='LogFile')
    arguements = parser.parse_args()
    
    return arguements.p, arguements.l

if __name__ == '__main__':
    port, log = serverside(sys.argv[1:])
    
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((socket.gethostname(), port))
    sock.listen(1)
    
    conn_object, clien_add = sock.accept()
    
    file = open(log, "w")
    keyword = 'network'
    stopWord = 'killswitch'
    
    print("Incoming Connection from (IP, PORT): " + str(clien_add))
    file.write("Incoming Connection from (IP, PORT): " + str(clien_add))
    
    while True:
        received = conn_object.recv(1024).decode()
        
        if str(received) == keyword:
            print("\nReceived: " + str(received))
            file.write("\nReceived: " + str(received))
            
            quoteFile = open('quotes.txt').read().splitlines()
            quote = random.choice(quoteFile)
            
            qMessage = quote
            
            print("\nSending: " + str(qMessage))
            file.write("\nSending: " + str(qMessage))

            conn_object.send(qMessage.encode())
        
        elif str(received) == stopWord:
            print("\nRecieved: " + str(received))
            file.write("\nRecieved: " + str(received))
            
            eMessage = "Stopping the server..."
            
            print("\nSending: " + str(eMessage))
            file.write("\nSending: " + str(eMessage))
            
            conn_object.send(eMessage.encode())

            print("\nShutting down server.")
            file.write("\nShutting down server.")
            
            break
        
        else:
            print("\nRecieved: " + str(received))
            file.write("\nRecieved: " + str(received))
            
            sMessage = "You entered the wrong word!"
            
            print("\nSending: " + str(sMessage))
            file.write("\nSending: " + str(sMessage))
            
            conn_object.send(sMessage.encode())

    conn_object.close()
