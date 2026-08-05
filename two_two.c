#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
int status;
printf("Running ps with execl\n");
if(fork()==0)
{
execl("ps","ps","-f",NULL);
perror("execl failed");
exit(1);
}
wait(&status);
if(WIFEXITED(status))
{printf("Child exit  with status:%d\n",WEXITSTATUS(status));
}
else
{
printf("Child did not exit successfully\n");
}
printf("Running ps with execlp (without full path)\n");
if(fork()==0)
{
execlp("ps","ps","-f",NULL);
perror("execlp failed");
exit(1);
}
wait(&status);
if(WIFEXITED(status))
{
printf("Child exited for execlp with status:%d\n",WEXITSTATUS(status));
}
else
{
printf("Child did not exit successfully\n");
}
printf("Done.\n");
return 0;
}

