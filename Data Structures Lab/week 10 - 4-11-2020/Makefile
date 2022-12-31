a.exe: tbtmain.o tbtimp.o 
	gcc -o a.exe tbtmain.o tbtimp.o 
tbtmain.o : tbtmain.c tbt.h
	gcc -c tbtmain.c
tbtimp.o : tbtimp.c tbt.h
	gcc -c tbtimp.c