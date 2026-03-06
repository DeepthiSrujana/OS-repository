#include <stdio.h>
#include <limits.h>
int main() {
    int n, i, time = 0, smallest, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];
    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d AT BT: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    while(completed != n) {
        smallest = -1;
        int min = INT_MAX;
        for(i = 0; i < n; i++){
                if(at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                smallest = i;
            }
        }
        if(smallest == -1) {
            time++;
        }
        else {
            rt[smallest]--;
            time++;
            if(rt[smallest] == 0) {
                completed++;
                ct[smallest] = time;
                tat[smallest] = ct[smallest] - at[smallest];
                wt[smallest] = tat[smallest] - bt[smallest];
            }
        }
    }
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}
