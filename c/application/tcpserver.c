#include<sys/socket.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/in.h>
#include<stdio.h>

#define SIZE 512

int main()
{
	int fd_sock,fd_file;
	struct sockaddr_in local,remote;
	socklen_t size = sizeof(remote);
	char buff[SIZE];
	fd_sock = socket(AF_INET,SOCK_STREAM,0);
	local.sin_family = AF_INET;
	local.sin_port = htons(50000);
	local.sin_addr.s_addr = INADDR_ANY;
	bind(fd_sock,(struct sockaddr *)&local,sizeof(local));
	listen(fd_sock,5);
	fd_sock = accept(fd_sock,(struct sockaddr *)&remote,&size);
	fd_file = open("/tmp/d",O_WRONLY | O_CREAT,0664);
	while(1)
	{
		int len = recv(fd_sock,buff,SIZE,0);
		if(len<=0)
			break;
		write(fd_file,buff,len);
	}
	close(fd_sock);
	close(fd_file);
}
