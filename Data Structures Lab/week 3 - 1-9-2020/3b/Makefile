a.exe: dllmain.o dllimp.o 
	gcc -o a.exe dllmain.o dllimp.o 
dllmain.o : dllmain.c dll.h
	gcc -c dllmain.c
dllimp.o : dllimp.c dll.h
	gcc -c dllimp.c