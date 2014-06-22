#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int fd;
	char buff[] = "hello world!\n";
	fd = open("/tmp/test",O_RDWR | O_CREAT,0664);
	if(fd < 0)
	{
		perror("open");
		return fd;
	}

	write(fd,buff,sizeof(buff));
	int len = read(fd,buff,sizeof(buff));
	printf("%s\n",buff);

	struct stat s;
	fstat(fd,&s);
	printf("File Size ---- %ld\n",(long)s.st_size);
	printf("File Owner---- %ld\n",(long)s.st_uid);
	close(fd);
	return 0;
}

