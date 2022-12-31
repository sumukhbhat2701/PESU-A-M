a.exe: seq_search.o seq_search_imp.o 
	gcc -o a.exe seq_search.o seq_search_imp.o 
seq_search.o : seq_search.c ss.h
	gcc -c seq_search.c
seq_search_imp.o : seq_search_imp.c ss.h
	gcc -c seq_search_imp.c