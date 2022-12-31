#include<stdio.h>
#include<unistd.h>
int main()
{
	// int pid = fork();
	// if(pid == 0)
	// {
	// 	printf("Entering child\n");
	// 	char *args[] = {"./sum","4","5","6","7",NULL};
	// 	execv(args[0],args);
	// }
    // else
    // {
    //     printf("parent\n");
    //     wait(NULL);

    // }
    fork();
    printf("1x\n");
    fork();
    printf("2y\n");
	return 0;
}