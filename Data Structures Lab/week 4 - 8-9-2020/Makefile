a.exe: cllmain.o cllimp.o 
	gcc -o a.exe cllmain.o cllimp.o 
cllmain.o : cllmain.c cll.h
	gcc -c cllmain.c
cllimp.o : cllimp.c cll.h
	gcc -c cllimp.c