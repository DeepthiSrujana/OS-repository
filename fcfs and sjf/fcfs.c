#include<stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[20], at[20], bt[20];
    int ct[20], tat[20], wt[20];
    printf("Enter Process ID, Arrival Time, Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int current_time = 0;
    for(i = 0; i < n; i++) {

        if(current_time < at[i]) {
            current_time = at[i];
        }

        ct[i] = current_time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        current_time = ct[i];
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    float total_tat = 0, total_wt = 0;
printf("1bf24cs338 deepthi  \n ");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
