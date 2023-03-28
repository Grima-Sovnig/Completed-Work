import socket
import sys
import struct
import random
import logging
import argparse

#Function to pack up data into a packet to send.
def packUp(version, messageType, messageLength, message):
    return struct.pack(f'! 3i {messageLength}s', version, messageType, messageLength, message.encode())

#Function to gather arguments from the command line.
def get_commandLine(argv=None):
    parser = argparse.ArgumentParser(description="LIGHTSERVER")
    parser.add_argument('-p', type=int, required=True, help='Port')
    parser.add_argument('-l', type=str, required=True, help='logFile')
    arguments = parser.parse_args()
    cPort = arguments.p
    logFile = arguments.l
    
    return cPort, logFile

if __name__ == '__main__':
    #Setting the Version and connection information.
    port, log = get_commandLine(sys.argv[1:])
    version = 17
    
    #Socket creation and binding it to the client to listen.
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((socket.gethostname(), port))
    s.listen(5)
    #Prints so the user can see a connection has been made.
    print("Started server on: ", socket.gethostname(), ":", port)
    
    connOb, address = s.accept()
    logFile = open(log, "w")
    
    print("Received connection from (IP, PORT): ", address)
    logFile.write(f"Received connection from (IP, PORT): {address}\n")
    
    received = connOb.recv(struct.calcsize('! 3i 5s'))
    version, msgType, msgLength, msg = struct.unpack('! 3i 5s', received)
    
    print("Received Data:\n\tVersion: \t", version,"\n\tMessage Type: \t", msgType, "\n\tMessage Length: ", msgLength)
    logFile.write(f"Received Data:\n\tVersion: \t{version} \n\tMessage Type: \t{msgType} \n\tMessage Length: {msgLength}\n")
    

    if version == version:
        print("\tVERSION ACCEPTED")
        logFile(f"\tVERSION ACCEPTED\n")
        
        print("\tReceived Message: ", msg)
        logFile(f"\tReceived Message: {msg}\n")
        
        if msgType == 3:
            
            message = "Hello"
            sendType = 3
            sendPacket = packUp(version, sendType, len(message), message)
            
            print("\tSending Message: ", message, "\n")
            logFile(f"\tSending Message: {message}\n\n")
            
            connOb.sendall(sendPacket)
        
        receivedT = connOb.recv(struct.calcsize('! 3i 7s'))
        verTwo, msgTypeTwo, msgLengthTwo, msgTwo = struct.unpack('! 3i 7s', receivedT)
        		
        print("Received Data:\n\tVersion: \t", verTwo,"\n\tMessage Type: \t", msgTypeTwo, "\n\tMessage Length: ", msgLengthTwo)
        logFile.write(f"Received Data:\n\tVersion: \t{verTwo} \n\tMessage Type: \t{msgTypeTwo} \n\tMessage Length: {msgLengthTwo}\n")

        if verTwo == version:
            print("\tVERSION ACCEPTED")
            logFile.write(f"\tVERSION ACCEPTED\n")

            if msgTypeTwo == 1:

                print(f"\tEXECUTING SUPPORTED COMMAND: ", msgTwo, "\n")
                logFile.write(f"\tEXECUTING SUPPORTED COMMAND: {msgTwo}\n")

                message = "SUCCESS"
                sendType = 1

            elif msgTypeTwo == 2:

                logFile.write(f"\tEXECUTING SUPPORTED COMMAND: {msgTwo}\n")
                print(f"\tEXECUTING SUPPORTED COMMAND: ", msgTwo, "\n")

                message = "SUCCESS"
                sendType = 2

            elif msgTypeTwo == 4:

                message = "DISCONN"
                sendType = 4
			
            else:
				
                logFile.write(f"\tIGNORING UNSUPPORTED COMMAND: {msgTwo}\n")
                print(f"\tIGNORING UNSUPPORTED COMMAND: ", msgTwo, "\n")

                message = "FAILURE"
                sendType = 6

        else:
            print("\tVERSION MISMATCH")
            logFile.write(f"\tERROR: VERSION MISMATCH")

            message = "FAILURE"
            sendType = 5

        sendPacket = packUp(version, sendType, len(message), message)
        connOb.sendall(sendPacket)

    else:
        print("VERSION MISMATCH")
        logFile.write(f"ERROR: VERSION MISMATCH")

        message = "FAILURE"
        sendType = 5

    sendPacket = packUp(version, sendType, len(message), message)
    connOb.sendall(sendPacket)

		
    
    
    
    
    