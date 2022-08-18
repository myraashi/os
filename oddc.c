#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/mman.h>

int main(int argc, char* argv[])
{
void *ptr;
pid_t pid;
int shmid;
const int SIZE = 4096;
shmid = shmget((key_t)1122,4096,0666);
ptr = shmat(shmid,NULL,0666);
printf("CHILD:\n");
int n = atoi(argv[1]);
for(int i = 1;i<2*n+1;i+=2)
{
sprintf(ptr,"%d\t",i);
printf("%d\t",i);
ptr += strlen(ptr);
}
shmctl(shmid, IPC_RMID, NULL);
}
