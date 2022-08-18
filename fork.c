#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
pid_t my_pid, child_pid, parent_pid, wid;
child_pid = fork();
if(child_pid < 0)
{
printf("Fork error\n");
exit(0);
}
if(child_pid == 0)
{
my_pid = getpid();
parent_pid = getppid();
printf("[CHILD] This is child process\n");
printf("[CHILD] My pid is %d\n",my_pid);
printf("[CHILD] My parent pid is %d\n",parent_pid);
printf("[CHILD] Loading another program\n");
execlp("/bin/pwd","pwd",NULL);
}

else
{
my_pid = getpid();
parent_pid = getppid();
printf("[PARENT] This is parent process\n");
printf("[PARENT]my pid :%d\n",my_pid);
printf("[PARENT]parent pid: %d\n",parent_pid);
printf("[PARENT]Child pid: %d\n",child_pid);
printf("[PARENT]Waiting for child process to terminate\n");
wid = wait(NULL);
printf("[PARENT]Resuming after terminarion of %d\n",wid);
printf("[PARENT]Exiting\n");
}
}
