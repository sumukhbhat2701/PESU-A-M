a.exe: hashmain.o hashimp.o 
	gcc -o a.exe hashmain.o hashimp.o 
hashmain.o : hashmain.c hash.h
	gcc -c hashmain.c
hashimp.o : hashimp.c hash.h
	gcc -c hashimp.c