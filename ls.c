#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>

void main(int argc, char* argv[])
{
DIR *d;
struct dirent *dir;
if(argc != 2)
{
printf("Pass the directory name as argument");
exit(0);
}
if((d = opendir(argv[1]))==NULL)
{
printf("Failed to open directory\n");
exit(0);
}
while((dir = readdir(d)) != NULL)
{
printf("%s\n",dir->d_name);
}
}

