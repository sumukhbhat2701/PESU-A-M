a.exe: queuemain.o queueimp.o 
	gcc -o a.exe queuemain.o queueimp.o 
queuemain.o : queuemain.c queue.h
	gcc -c queuemain.c
queueimp.o : queueimp.c queue.h
	gcc -c queueimp.c