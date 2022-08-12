#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

void main()
{
    pid_t my_pid, child_pid, parent_pid;
    child_pid = fork();
    if(child_pid < 0)
    {
        printf("Forking error\n");
        exit(0);
    }
    else
    {
        if(child_pid==0)
        {
            parent_pid = getppid();
            my_pid = getpid();
            printf("[CHILD]This is child process\n");
            printf("[CHILD]My pid is %d\n",my_pid);
            printf("[CHILD]My parent's pid is %d\n",parent_pid);
            printf("[CHILD]Sleeping for 10 10 seconds\n");
            sleep(10);
            printf("[CHILD]My parent ended, hence I am an orphan process adopted by init process.\nParent pid:%d",getppid());
        }
        else
        {
            parent_pid = getppid();
            my_pid = getpid();
            printf("[PARENT]This is parent process");
            printf("[PARENT]My pid is %d",my_pid);
            printf("[PARENT]My parent's pid is %d",parent_pid);
            printf("[PARENT]child pid is %d",child_pid);
        }
        
    }
}