#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
int k = 2, n1,n2,n3;
void *ptr;
const int SIZE  = 4096;
pid_t pid;
int shm_fd;
shm_fd = shm_open("OS",O_CREAT | O_RDWR, 0666);
ftruncate(shm_fd, 4096);
ptr = mmap(0,SIZE,PROT_WRITE, MAP_SHARED, shm_fd, 0);
printf("CHILD\n");
int i = atoi(argv[1]);
n1 = 0; n2 = 1;
sprintf(ptr , "%d" , n1);
ptr += strlen(ptr);
printf("%d",n1);
sprintf(ptr , "%d" , n2);
ptr += strlen(ptr);
printf("%d",n2);
while(k!=i)
{
n3 = n1 +n2;
sprintf(ptr,"%d",n3);
printf("%d\n",n3);
n1 = n2; n2= n3;
ptr += strlen(ptr);
k++;
}
}
