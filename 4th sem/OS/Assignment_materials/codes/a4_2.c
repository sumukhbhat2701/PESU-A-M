 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{

	int fd = open("os.txt",O_WRONLY);
	if(fd<0) return 0;
	lseek(fd,0,SEEK_SET);
	fd = open("os.txt",O_TRUNC);
	if(fd<0) return 0;
	close(fd);
	return 0;

}
