 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{

	int fd = open("os8.txt",O_CREAT|O_RDWR,0755);
	if(fd<0) { printf("error"); return 0; }
	char s1[] = "Hello world";
	//lseek(fd,7,SEEK_SET);
	//lseek(fd,-1000,SEEK_CUR);
	write(fd,"z",1);
	//lseek(fd,0,SEEK_SET);
	//write(fd,"heyman",6);
	printf("%ld\n",lseek(fd,0,SEEK_CUR));
	close(fd);
	return 0;

}
