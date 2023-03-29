# Gabriel Snider Project 3 CSC 4200
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

#Not going to comment this because most of the comments for the client apply to the logic used here.
if __name__ == '__main__':
    port, log = get_commandLine(sys.argv[1:])
    version = 17
    
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((socket.gethostname(), port))
    sock.listen(5)
    
    print("Started server on: ", socket.gethostname(), ":", port)
    
    connection, client = sock.accept()
    log = open(log, "w")
    
    print("Received connection from (IP, PORT): ", client)
    log.write(f"Received connection from (IP, PORT): {client}\n")
    
    received = connection.recv(struct.calcsize('! 3i 5s'))
    version, messageType, messageLength, message = struct.unpack('! 3i 5s', received)
    
    print("Received Data:\n\tVersion: \t", version,"\n\tMessage Type: \t", messageType, "\n\tMessage Length: ", messageLength)
    log.write(f"Received Data:\n\tVersion: \t{version} \n\tMessage Type: \t{messageType} \n\tMessage Length: {messageLength}\n")
    
    if version == version:
        print("\tVERSION ACCEPTED")
        log.write(f"\tVERSION ACCEPTED\n")
        
        print("\tReceived Message: ", message)
        log.write(f"\tReceived Message: {message}\n")
        
        if messageType == 3:
            message = "Hello"
            typeSend = 3
            sendPacket = packUp(version, typeSend, len(message), message)
            
            print("\tSending Message: ", message, "\n")
            log.write(f"\tSending Message: {message}\n\n")
            
            connection.sendall(sendPacket)
        
        receivedTwo = connection.recv(struct.calcsize('! 3i 7s'))
        versionTwo, messageTypeTwo, messageLengthTwo, messageTwo = struct.unpack('! 3i 7s', receivedTwo)
        
        print("Received Data:\n\tVersion: \t", versionTwo, "\n\tMessage Type: \t", messageTypeTwo, "\n\tMessage Length: ", messageLengthTwo)
        log.write(f"Received Data:\n\tVersion: \t{versionTwo} \n\tMessageType: \t{messageTypeTwo} \n\tMessage Length: {messageLengthTwo}\n")
        
        if versionTwo == version:
            
            print("\tVERSION ACCEPTED")
            log.write(f"\tVERSION ACCEPTED\n")
            
            if messageTypeTwo == 1:
                print(f"\tEXECUTING SUPPORTED COMMAND: ", messageTwo, "\n")
                log.write(f"\tEXECUTING SUPPORTED COMMAND: {messageTwo}\n")
                
                message = "SUCCESS"
                typeSend = 1
            
            elif messageTypeTwo == 2:
                log.write(f"\tEXECUTING SUPPORTED COMMAND: {messageTwo}\n")
                print(f"\tEXECUTING SUPPORTED COMMAND: ", messageTwo, "\n")
                
                message = "SUCCESS"
                typeSend = 2
            
            elif messageTypeTwo == 4:
                message = "DISCONNECTED"
                typeSend = 4
            
            else:
                log.write(f"\tIGNORING UNSUPPORTED COMMAND: {messageTwo}\n")
                print(f"\tIGNORING UNSUPPORTED COMMAND: ", messageTwo, "\n")
                
                message = "FAILURE"
                typeSend = 6
        else:
            print("\tVERSION MISMATCH")
            log.write(f"\tERROR: VERSION MISMATCH")
            
            message = "FAILURE"
            typeSend = 5
        
        sendPacket = packUp(version, typeSend, len(message), message)
        connection.sendall(sendPacket)
    
    else:
        print("VERSION MISMATCH")
        log.write(f"ERROR: VERSION MISMATCH")
        
        message = "FAILURE"
        typeSend = 5
    
    sendPacket = packUp(version, typeSend, len(message), message)
    connection.sendall(sendPacket)

    
    
    
    