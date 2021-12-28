#include<string.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid_t zpid;
	for(int i = 0;i<10; i++){

		pid = fork();
		if(pid==0) break;
	}
	if(pid>0){
		printf("parent process pid[%d]\n", getpid());
		//多子进程模型，采用循环回收
		while((zpid = wait(NULL))!= -1)
		{
		printf("parent wait sucessly, zombie pid %d\n",zpid);
		}
	}else if(pid==0)
	{
		printf("chile process pid[%d]\n",getpid());
		exit(0);
	}else
	{
		perror("fork call failed");
		exit(0);
	}
}
