#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/in.h>


#define SIZE 512

int main(int argc,char *argv[])	
{
	char *filename,*ip;
	char buff[SIZE];
	struct sockaddr_in addr;
	int fd_socket,fd_file;
	if(argc < 3)
	{
		printf("usage:./udpclient ip filepath\n");
		return 0;
	}

	ip = argv[1];
	filename = argv[2];
	fd_socket = socket(AF_INET,SOCK_DGRAM,0);
	fd_file = open(filename,O_RDONLY);
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(50000);
	addr.sin_addr.s_addr = inet_addr(ip);
	memset(buff,'\0',sizeof(buff));

	while(1)
	{
		int len = read(fd_file,buff,SIZE);
		sendto(fd_socket,buff,SIZE,0,(struct sockaddr *)&addr,sizeof(addr));
		if(len < 512)
		{
			printf("break");
			break;
		}
	}
	close(fd_socket);
	close(fd_file);
}

