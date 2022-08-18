#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>

void main(int argc, char *argv[])
{
pid_t pid;
const int SIZE = 4096;
int shmid;
void *ptr;
if(argc<2)
{
printf("Error: n not given");
exit(0);
}
pid = fork();
shmid = shmget((key_t)1122,4096,0666 | IPC_CREAT);//tells the system to create a new memory segment
ptr = shmat(shmid,NULL,0666);
if(pid ==0)
{
execlp("./fib" , "fib" , argv[1],NULL);
}
else if(pid>0)
{
wait(NULL);
printf("PARENT: child completed\n");
printf("Parent printing:\n");
printf("%s",(char*)ptr);
shmdt(ptr);//deatch fromt the memory segment
}
}

