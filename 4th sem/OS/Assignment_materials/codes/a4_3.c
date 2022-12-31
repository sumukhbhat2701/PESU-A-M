 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{

	int fd = open("os.txt",O_WRONLY);
	write(fd,"Hello world",11);
	printf("FILE SIZE=%ld",lseek(fd,0,SEEK_END));
	link("os.txt","os1.txt");
	int fd2 = open("os1.txt",O_WRONLY);
	lseek(fd2,0,SEEK_END);
	write(fd2," from OS",8);
	printf("%ld %ld\n",lseek(fd,0,SEEK_END),lseek(fd2,0,SEEK_END));
	return 0;

}
