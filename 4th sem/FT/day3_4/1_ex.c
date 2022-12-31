#if 0
#include <stdio.h>
int a = 10;

int main()
{
	printf("val : %d addr : %p\n", a, &a);
}
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
// fork :
//		creates a new process
//		returns twice
//		once in the parent : pid of the child
//		once again in the child : 0

int main()
{
//	srand(getpid());
//	printf("%d\n", rand() % 100);


#if 0
	int pid;
	pid = fork();
	if(pid) // parent
	{
		printf("parent pid %d\n", getpid());
	}
	else // child
	{
		printf("child pid %d\n", getpid());
	}
#endif

	int n = 10;
	srand(getpid());
	int pid;
	pid = fork();
	if(pid) // parent
	{
		sleep(rand() % 3);
		n += 5;
		printf("parent pid %d addr of n : %p n : %d\n", getpid(), &n, n);
	}
	else // child
	{
		sleep(rand() % 3);
		n += 15;
		printf("child pid %d addr of n : %p n : %d\n", getpid(), &n, n);
	}	
	sleep(rand() % 3);
	printf("out of block pid  %d addr of n : %p n : %d\n", getpid(), &n, n);
}
// address of a variable : offset in the virtual address space
// on forking, variables will continue to have the same offset in both,
//	but the location is not shared




