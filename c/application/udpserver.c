#include<stdio.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/in.h>

#define SIZE 512

int main()
{
	char buff[SIZE];
	socklen_t len = sizeof(struct sockaddr_in);
	int fd_file,fd_sock;
	struct sockaddr_in local,remote;
	fd_sock = socket(AF_INET,SOCK_DGRAM,0);
	local.sin_family = AF_INET;
	local.sin_port = htons(50000);
	local.sin_addr.s_addr = INADDR_ANY;
	bind(fd_sock,(struct sockaddr *)&local,len);
	fd_file = open("/tmp/c",O_WRONLY | O_CREAT,0664);
	while(1)
	{
		int l = recvfrom(fd_sock,buff,0,0,(struct sockaddr *)&remote,&len);
		write(fd_file,buff,l);
		if(l < 512)
		{
			printf("break");
			break;
		}
	}
	close(fd_sock);
	close(fd_file);
	return 0;
}
