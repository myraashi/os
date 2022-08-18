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

int main(int argc, char* argv[])
{
pid_t pid;
const int SIZE = 4096;
int shm_fd = shm_open("OS",O_CREAT | O_RDWR,0666);
ftruncate(shm_fd,0666);
void *ptr = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shm_fd,0);
printf("CHILD:\n");
int m = atoi(argv[1]),n = atoi(argv[2]);
for(int i = m;i<=n;i++)
{
if(i<2)
continue;
int flag = 1;
for(int j=2;j<=i/2;j++)
{
if(i%j == 0)
{
flag=0;
break;
}
}
if(flag)
{
sprintf(ptr,"%d\t",i);
printf("%d\t",i);
ptr += strlen(ptr);
}
}
return 0;
}
