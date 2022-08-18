#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

void main()
{
pid_t my_pid,parent_pid, child_pid;
child_pid = fork();
if(child_pid < 0)
{
printf("Forking error");
exit(0);
}
else
{
if(child_pid==0)
{
parent_pid = getppid();
my_pid = getpid();
printf("\n[CHILD]This is child's process\n");
printf("[CHILD]my pid: %d\n",my_pid);
printf("[CHILD]parent pid :%d\n",parent_pid);
}
else{
parent_pid = getppid();
my_pid = getpid();
printf("\n[PARENT]This is parent process\n");
printf("[PARENT]my pid: %d\n",my_pid);
printf("[PARENT]parent pid: %d\n",parent_pid);
printf("[PARENT]child pid: %d\n",child_pid);
sleep(10);
printf("[PARENT]child pid %d has ended but it still has entry in the process table. It is a zombie process.",child_pid);
}
}

}

