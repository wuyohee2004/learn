#include<fcntl.h>
#include<stdio.h>
#include<sys/ioctl.h>
#include<linux/cdrom.h>

#define DEVICE "/dev/sr0"

int main()
{
	int fd = open(DEVICE,O_RDONLY | O_NONBLOCK);//NONBLOCK=execute immd
	ioctl(fd,CDROMEJECT);
	close(fd);
	return 0;
}


