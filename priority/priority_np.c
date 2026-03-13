#include<stdio.h>

int main(){
int n,i;

printf("enter no. of process \n");
scanf("%d",&n);

int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],pr[n];
int co[n];

for(i=0;i<n;i++){
    pid[i]=i+1;

    printf("enter at ");
    scanf("%d",&at[i]);

    printf("enter bt ");
    scanf("%d",&bt[i]);

    printf("enter priority ");
    scanf("%d",&pr[i]);

    co[i]=0;
}

int curr=0;
int count=0;
int sumt=0,sumwt=0;

double avg_tat,avg_wt;

while(count<n){
    int high=9999;
    int s=-1;

    for(i=0;i<n;i++){
        if(at[i]<=curr && co[i]==0){
            if(pr[i]<high){
                high=pr[i];
                s=i;
            }
        }
    }

    if(s==-1){
        curr++;
    }
    else{
        ct[s]=curr+bt[s];
        tat[s]=ct[s]-at[s];
        wt[s]=tat[s]-bt[s];

        curr=ct[s];
        co[s]=1;
        count++;
    }
}

for(i=0;i<n;i++){
    sumt+=tat[i];
    sumwt+=wt[i];
}

avg_tat=(double)sumt/n;
avg_wt=(double)sumwt/n;

printf("pid\tat\tbt\tpr\tct\ttat\twt\n");

for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
}

printf("average tat %.2lf\n",avg_tat);
printf("average wt %.2lf\n",avg_wt);

return 0;
}
