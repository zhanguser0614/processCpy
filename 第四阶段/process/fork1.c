#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(void)
{
	pid_t pid;
	pid_t zpid;
	pid =fork();
	int status;
	if(pid>0){
		printf("parent pid %d\n",getpid());
		zpid = wait(&status);//传出子进程退出信息
		if(WIFEXITED(status))
		{
			printf("回收成功，僵尸pid %d，进程正常退出 exit or return. 退出码：%d\n",zpid,WEXITSTATUS(status));

		}
		//异常退出校验
		if(WIFSIGNALED(status))
		{
			printf("回收成功，僵尸pid %d，进程异常退出（被外部信号杀死）. 信号编号：%d\n",zpid,WEXITSTATUS(status));
		}
		//校验子进程退出信息
	}
	else if(pid == 0)
	{
		printf("child pid %d\n",getpid());
		while(1);
	}else
	{
		
	}
}
