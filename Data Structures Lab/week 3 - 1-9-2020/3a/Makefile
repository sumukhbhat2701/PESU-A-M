a.exe: polymain.o polyimp.o 
	gcc -o a.exe polymain.o polyimp.o 
polymain.o : polymain.c poly.h
	gcc -c polymain.c
polyimp.o : polyimp.c poly.h
	gcc -c polyimp.c