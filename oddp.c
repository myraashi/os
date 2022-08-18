#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
 void *ptr;
 pid_t pid;
 int shmid;
 const int SIZE  = 4096;
 if(argc<2)
 {
  printf("No N passed");
  exit(0);
 }
 pid = fork();
 shmid = shmget((key_t)1122,4096,0666|IPC_CREAT);
 ptr = shmat(shmid, NULL, 0666);
 if(pid==0)
 {
  execlp("./oddc","oddc",argv[1],NULL);
 }
 else if (pid>0)
 { 
   wait(NULL);
   printf("PARENT:child completed\n");
   printf("Parent is printing\n");
   printf("%s",(char*)ptr);
   shmdt(ptr);
 }
}
