#include<stdio.h>
struct process{
    int id,at,bt,ct,tt,wt,comp;
};
void main()
{
    int n , i ,j;
    float total_wt=0, total_tat=0;
    struct process p[10];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the process arrival time and the burst time:");
    for(i = 0;i<n;i++)
    {
        printf("%d process",i+1);
        scanf("%d%d",p[i].at,p[i].bt);
    }
    int min_index, min_bt, comp = 0, cur_time = 0;
    while(comp!=n)
    {
        min_index = -1;
        min_bt = 999;
        for(i = 0;i<n;i++)
        {
            if(p[i].at<=cur_time && p[i].comp == 0)
            {
                if(p[i].bt<min_bt || p[i].bt==min_bt && p[i].at<p[min_index].at)
                {
                    min_bt = p[i].bt;
                    min_index = i;
                }
            }
        }
        if(min_index == -1)
            cur_time++;
        else
        {
            cur_time += p[min_index].bt;
            p[min_index].ct += cur_time;
            p[min_index].tt = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tt - p[min_index].bt;
            total_tat += p[min_index].tt;
            total_wt += p[min_index].wt;
            p[min_index].comp = 1;
            comp++;
            printf("|P%d(%d)  %d",p[min_index].id,p[min_index].bt,cur_time);
            
        }
        
    }
}