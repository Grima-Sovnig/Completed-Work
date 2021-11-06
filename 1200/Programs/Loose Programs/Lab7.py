def Fib(num):
    if(num<= 1):
        return num
    else:
        return (Fib(num - 1))+ Fib(num - 2)