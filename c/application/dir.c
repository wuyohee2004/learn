#include<dirent.h>
#include<stdio.h>

int main()
{
	struct dirent *dirent;
	DIR *dir = opendir("/tmp");
	while(dirent = readdir(dir))
		printf("%s \n",dirent->d_name);
}


