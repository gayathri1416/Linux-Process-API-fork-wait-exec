#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int pid = fork();
if(pid==0)
{
printf("I am child process, my PID is %d\n",getpid());
printf("I am parent process, my PID is %d\n",getppid());
sleep(2);
}
else
{
printf("I am parent process, my PID is %d\n",getpid());
wait(NULL);
}
}
