#include<stdio.h>
#include<string.h>
void main()
{
FILE *f;
char filename[100], pat[100],temp[100];
printf("Enter filename:\n");
scanf("%s",filename);
printf("Enter pattern to be searched:\n");
scanf("%s",pat);
f = fopen(filename,"r");
while(!feof(f))
{
fgets(temp,100,f);
if(strstr(temp,pat))
printf("%s",temp);
else
printf("Not found");
}
fclose(f);
}
