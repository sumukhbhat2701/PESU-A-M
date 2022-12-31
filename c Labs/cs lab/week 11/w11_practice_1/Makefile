a.exe: client.o server.o 
	gcc -o a.exe client.o server.o 
client.o : client.c server.h
	gcc -c client.c
server.o : server.c server.h
	gcc -c server.c
