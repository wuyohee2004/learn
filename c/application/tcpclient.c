#include<stdio.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/in.h>

#define SIZE 512

int main(int argc,char* argv[])
{
	int fd_file,fd_sock;
	char *ip,*filename;
	char buff[SIZE];
	struct sockaddr_in addr;
	if(argc < 3)
		return 0;
	ip = argv[1];
	filename = argv[2];
	fd_sock = socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(50000);
	addr.sin_addr.s_addr = inet_addr(ip);
	connect(fd_sock,(struct sockaddr *)&addr,sizeof(addr));

	fd_file = open(filename,O_RDONLY);
	while(1)
	{
		int len = read(fd_file,buff,SIZE);
		if(len <=0)
			break;
		send(fd_sock,buff,len,0);

	}
	return 0;
}

