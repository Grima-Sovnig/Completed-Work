import socket
import struct
import argparse
import sys
from cmath import rect

#Function to create the packet structure
def packUp(fv, fmt, fml, fm):
    return struct.pack(f'! 3i {fml}s', fv, fmt, fml, fm.encode())

# Function to get the command line arguments.
def get_commandLine(argv=None):
    parser = argparse.ArgumentParser(description="LIGHTCLIENT")
    parser.add_argument('-p', type=int, required=True, help='Port')
    parser.add_argument('-l', type=str, required=True, help='logFile')
    parser.add_argument('-s', type=str, required=True, help='Server')
    
    args = parser.parse_args()
    port = args.p
    log = args.l
    address = args.s

    return port, log, address


# Begin Main Function
if __name__ == '__main__':
    
    #Variable Setup for the IP, Port, and File Name
    port, log, server = get_commandLine(sys.argv[1:])
    
    #Creating the Socket for the Client
    cSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    address = (server, port)
    logFile = open(log, "w")
    #Connecting to provided server with client.
    cSocket.connect(address)
    #Letting user know the server connected and writing it to the log.
    print("Sucessfully connected to (IP, PORT): ", address)
    logFile.write(f"Connected to (IP, PORT): {address}")
    
    #Setup for sending to the server.
    messageToSend = "HELLO"
    mesLen = len(messageToSend)
    versionToSend = 17
    typeToSend = 3
    
    print("Sending ", messageToSend)
    logFile.write(f"Sending {messageToSend}")
    #Compiling data into a packet for the server.
    packet = packUp(versionToSend, typeToSend, mesLen, messageToSend)
    cSocket.send(packet)
    
    #Receiving and unpacking data from the server.
    received = cSocket.recv(struct.calcsize('! 3i 5s'))
    recievedVersion, recievedMessageType, recievedMessageLength, recievedMessage = struct.unpack('! 3i 5s', received)
    print("Received Data: \n\tversion: \t", recievedVersion," \n\tmessage_type: \t", recievedMessageType," \n\tlength: \t", recievedMessageLength)
    logFile.write(f"Received Data: \n\tversion: \t{recievedVersion} \n\tmessage_type: \t{recievedMessageType} \n\tlength: \t{recievedMessageLength}")

    #Version Checking
    if versionToSend == recievedVersion:
        print("\tVERSION ACCEPTED")
        logFile.write("\tVERSION ACCEPTED")
        
        print("\tReceived: ", recievedMessage)
        logFile.write(f"\tReceived {recievedMessage}")
    else:
        print("VERSION MISMATCH")
        logFile.write("VERSION MISMATCH")
        