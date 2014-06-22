#include<unistd.h>
#include<stdio.h>
#include<sys/msg.h>
#include<string.h>

#define KEY 250

struct msgbuf
{
	int index;
	char buff[20];
};

int main()
{
	int id = msgget(KEY,IPC_CREAT);
	int pid = fork();
	if(pid == 0)
	{
		struct msgbuf buf;
		buf.index = 1;
		strncpy(buf.buff,"hello world",sizeof(buf.buff));
		while(1)
		{
			msgsnd(id,&buf,sizeof(buf),0);
			buf.index++;
			sleep(1);
		}
	}
	else if(pid > 0)
	{
		struct msgbuf buf;
		while(1)
		{
			msgrcv(id,&buf,sizeof(buf),0,0);
			printf("%s%d\n",buf.buff,buf.index);
			sleep(2);
		}
	}
	return 0;
}
			

