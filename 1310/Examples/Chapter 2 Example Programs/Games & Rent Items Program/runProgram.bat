cls
del *.o
del Business.exe

make

Business < TEST_CASE.txt > RESULT_OF_TEST_CASE.txt