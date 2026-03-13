#include<stdio.h>
int main(){
    int n,i;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],pr[n];
    int rt[n],ct[n],tat[n],wt[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter Process ID: ");
        scanf("%d",&pid[i]);
        printf("Enter Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Enter Burst Time: ");
        scanf("%d",&bt[i]);
        printf("Enter Priority: ");
        scanf("%d",&pr[i]);
        rt[i]=bt[i];
    }
    int current_time=0;
    int completed=0;
    int sum_tat=0,sum_wt=0;
    double avg_tat,avg_wt;
    while(completed<n)
    {
        int highest_priority=9999;
        int selected=-1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=current_time && rt[i]>0)
            {
                if(pr[i]<highest_priority)
                {
                    highest_priority=pr[i];
                    selected=i;
                }
            }
        }
        if(selected==-1)
        {
            current_time++;
        }
        else
        {
            rt[selected]--;
            current_time++;
            if(rt[selected]==0)
            {
                ct[selected]=current_time;
                tat[selected]=ct[selected]-at[selected];
                wt[selected]=tat[selected]-bt[selected];
                sum_tat+=tat[selected];
                sum_wt+=wt[selected];
                completed++;
            }
        }
    }
    avg_tat=(double)sum_tat/n;
    avg_wt=(double)sum_wt/n;
    printf("usn 1bf24cs338\n");
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2lf",avg_tat);
    printf("\nAverage Waiting Time = %.2lf",avg_wt);
    return 0;
}
