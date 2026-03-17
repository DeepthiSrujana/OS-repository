#include<stdio.h>
int main(){
int n,i;
printf("enter no. of process \n");
scanf("%d",&n);
int pid[n],at[n],bt[n],ct[n],tat[n],wt[n];
int fi[n];
for(int i=0;i<n;i++){
    pid[i]=i+1;
    printf("enter at ");
    scanf("%d",&at[i]);
    printf("enter bt ");
    scanf("%d",&bt[i]);
    fi[i]=0;
}
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(at[i]>at[j]){
            int temp;
            temp=at[i];
            at[i]=at[j];
            at[j]=temp;
            temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;
            temp=pid[i];
            pid[i]=pid[j];
            pid[j]=temp;
        }
    }
}
int curr=0;
int comp=0;
while(comp<n){
   int k=-1;
for(int i=0;i<n;i++){
    if(at[i]<=curr && fi[i]==0){
        if(k==-1 || bt[i]<bt[k]){
            k=i;
        }
    }
}
if(k==-1){
    curr++;
}
else{
    ct[k]=curr+bt[k];
    tat[k]=ct[k]-at[k];
    wt[k]=tat[k]-bt[k];
    curr=ct[k];
    fi[k]=1;
    comp++;
}
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
