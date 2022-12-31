a.exe: heapmain.o heapimp.o 
	gcc -o a.exe heapmain.o heapimp.o 
heapmain.o : heapmain.c heap.h
	gcc -c heapmain.c
heapimp.o : heapimp.c heap.h
	gcc -c heapimp.c