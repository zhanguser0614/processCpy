#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid = fork();

	if(pid>0)
	{
		printf("parent pid %d exec jobs\n",getpid());
		while(1)
		sleep(1);
	}
	else if(pid == 0)
	{
		printf("child pid %d exec jobs\n",getpid());
		execl("/usr/bin/firefox","firefox","firefox","https:/www.bilibilicom",NULL);
		printf("execl firefox sueccess..\n");
	}
	else{
		perror("fork error");
		exit(0);
	}
	return 0;
}
