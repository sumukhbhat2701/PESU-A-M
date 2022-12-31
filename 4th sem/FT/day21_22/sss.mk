a.out : client.o state.o list.o
	gcc client.o state.o list.o
client.o : client.c state.h
	gcc -c client.c
state.o : state.c state.h
	gcc -c state.c
list.o : list.h list.c
	gcc -c list.c	
