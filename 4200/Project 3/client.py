# Gabriel Snider Project 3 CSC 4200
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
    
    # Sets variables equal to the arguments gained from the command line.
    args = parser.parse_args()
    port = args.p
    log = args.l
    address = args.s

    return port, log, address


# Begin Main Function
if __name__ == '__main__':
    #Uses previous function to set the port, file name, server
	port, log, server = get_commandLine(sys.argv[1:])
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sAddr = (server, port)
    #Opens file for logging
	log = open(log, "w")
	#Connects the socket to the supplied address.
	sock.connect(sAddr)
	
	print("Connected to (IP, PORT): ", sAddr)
	log.write(f"Connected to (IP, PORT): {sAddr}")
    #Specs for the message to be sent.
	sendingMessage = "HELLO"
	sendingMessageLength = len(sendingMessage)
	sendingVersion = 17
	sendingMessageType = 3

	print("Sending ", sendingMessage)
	log.write(f"Sending {sendingMessage}")
	#Uses structure function made earlier to wrap data in a packet.
	sendPacket = packUp(sendingVersion, sendingMessageType, sendingMessageLength, sendingMessage)
    #Uses the socket to send packaged data to server.
	sock.send(sendPacket)
    #Client then listens and receives a response from the server.
	sReceived = sock.recv(struct.calcsize('! 3i 5s'))
    #Unpackages received data and assigns it to variables.
	recievedVersion, recievedMessageType, recievedMessageLength, recievedMessage = struct.unpack('! 3i 5s', sReceived)
	
	print("Received Data: \n\tversion: \t", recievedVersion," \n\tmessage_type: \t", recievedMessageType," \n\tlength: \t", recievedMessageLength)
	log.write(f"Received Data: \n\tversion: \t{recievedVersion} \n\tmessage_type: \t{recievedMessageType} \n\tlength: \t{recievedMessageLength}")
    #Checking Version and decided based on supplied information how to respond. 
	if sendingVersion == recievedVersion:
		print("\tVERSION ACCEPTED")
		log.write("\tVERSION ACCEPTED")
		
		print("\tReceived: ", recievedMessage)
		log.write(f"\tRecived {recievedMessage}")

		sendingMessage = "LIGHTON"
		sendingMessageLength = len(sendingMessage)
		sendingMessageType = 2

		print("\tSending Command: ", sendingMessage)
		log.write(f"\tSending Command: {sendingMessage}")

		sendPacket = packUp(sendingVersion, sendingMessageType, sendingMessageLength, sendingMessage)
		sock.sendall(sendPacket)

		sReceived = sock.recv(struct.calcsize('! 3i 7s'))
		recievedVersion, recievedMessageType, recievedMessageLength, recievedMessage = struct.unpack('! 3i 7s', sReceived)
		
		print("Received Data: \n\tversion: \t", recievedVersion," \n\tmessage_type: \t", recievedMessageType," \n\tlength: \t", recievedMessageLength)
		log.write(f"Received Data: \n\tversion: \t{recievedVersion} \n\tmessage_type: \t{recievedMessageType} \n\tlength: \t{recievedMessageLength}")

		if sendingVersion == recievedVersion:
			print("\tVERSION ACCEPTED")
			log.write("\tVERSION ACCEPTED")
			
			print("\tReceived: ", recievedMessage)
			log.write(f"\tRecived {recievedMessage}")

		else:
			print("VERSION MISMATCH")
			log.write("VERSION MISMATCH")
			
	else:
		print("VERSION MISMATCH")
		log.write("VERSION MISMATCH")
