#include<stdio.h>
#include<unistd.h>//lseek command, read, write
#include<fcntl.h>//ORDNLY command

void main()
{
    char filename[100],buffer[100];
    int fd, n;
    printf("Enter filename:\n");
    scanf("%s",filename);
    //open file in read only mode
    fd = open(filename,O_RDONLY);
    
    
    printf("\nReading 10 characters from the file\n");
    n = read(fd, buffer,10);
    write(0,buffer,n);

    printf("\nSkipping 5th character from the file\n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(0, buffer,n);

    printf("\nGoing to last 5th character from the file\n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(0, buffer,n);


    printf("\nGoing to third character in the file\n");
    lseek(fd, 3,SEEK_SET);
    n = read(fd, buffer,10);
    write(0,buffer,n);

}