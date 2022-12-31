#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid = fork();
	if(pid == 0)
	{
		printf("Entering child\n");
		char *args[] = {"./sum","4","5","6","7",NULL};
		execv(args[0],args);
	}
	return 0;
}
