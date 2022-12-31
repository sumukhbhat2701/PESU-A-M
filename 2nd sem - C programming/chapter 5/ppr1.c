#include <stdio.h>
int main(int argc, char *argv[])
{
	if(argc<2)
		printf("The file name is %s",argv[0]);
	else
		for(int i=0;i<argc;i++)
		{
			printf("the argument %d passed are %d \n",i,argv[i]);
		}
}