#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid, at,bt,ct,wt,tt;
};
struct process a[10];
float total_wt = 0, total_tt = 0;
void sort(struct process list[],int n)
{
    int i , j;
    struct process temp;
    for (i = 0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(list[j].at>list[j+1].at)
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    for(i = 0;i<n;i++)
    {
        list[i].ct = list[i].wt = list[i].tt = 0;
    }
}

void turnaroundtime(struct process a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        a[i].tt = a[i].ct - a[i].at;
        total_tt += a[i].tt;
    }
}

void waitingtime(struct process a[], int n)
{
    for(int i = 0;i<n;i++)
    {
        a[i].wt = a[i].tt - a[i].bt;
        total_wt += a[i].wt;
    }
}

void avgtime(struct process a[], int n)
{
    sort(a,n);
    int ct = a[0].at + a[0].bt;
    a[0].ct = ct;
    for(int i = 1;i<n;i++)
    {
        ct += a[i].bt;
        a[i].ct = ct;
    }
    turnaroundtime(a,n);
    waitingtime(a,n);
    printf("PID\tAT\tBT\tCT\tWT\tTT\n");
    for(int i =0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].wt,a[i].tt);
    }
    printf("\nAvg waiting time = %.3f\nAverage turnaround time  = %.3f\n",total_wt/n,total_tt/n);
}

void main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
        printf("Enter the pid, arrival time and burst time;\n");
    for(int i = 0;i<n;i++)
    {
        printf("For process %d\n",i+1);
        scanf("%d%d%d",&a[i].pid, &a[i].at ,&a[i].bt);
    }
    avgtime(a,n);

}
