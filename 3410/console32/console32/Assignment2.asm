.586
.MODEL FLAT
.STACK 4096

.DATA
primeArray	DWORD	2, 3, 98 DUP (?)
primeCount	DWORD	2
primeCan	DWORD	5
index		DWORD	1

.CODE
main		PROC


whileLoop:		cmp primeCount, 100			; Compares primeCount to 100, if it is equal to 100 we have found all the needed primes.
				jge canidateCheck			; Jumps to canidateCheck if primeCount is greater than or equal to 100
				mov index, 1				; Moves 1 into the index variable.
				lea esi, primeArray			; Retrives the starting address for primeArray
				



canidateCheck:	mov edi, primeCount			; Moves primeCount to edi
				cmp index, edi				; Compares the current index value to edi (the amount of primes).
				jg addPrime					; Jumps to addPrime if the index is greater than the amount of primes.
				mov eax, primeCan			; Moves primeCand into eax.
				mov ebx, [esi]				; Moves the value stored in that address of esi into ebx.
				mov edx, 0					; Moves zero into edx.
				div ebx						; Divides to see if there is a remainder to determine if number is prime.
				cmp edx, 0					; Compares edx to zero.
				je arrayInc					; If edx is equal to zero jump to arrayInc.
				inc index					; Increases the index by 1
				add esi, 4					; Adds for to esi to get to next array element.
				jmp canidateCheck			; Jumps to canidateCheck


addPrime:		add primeCount, 1			; Adds 1 to primeCount.
				mov eax, primeCan			; Moves the primeCand into eax.
				mov [esi], eax				; Moves the primeCand into the array.
				loop whileLoop				; Loops the whileLoop.

arrayInc:		add primeCan, 2			; Adds 2 to the primeCand.
				add esi, 4					; Adds 4 to get to the next array element.
				loop whileLoop				; Loops the whileLoop.

endWhile:		mov eax, 0					; Exits with return code 0
				ret
main			ENDP
END