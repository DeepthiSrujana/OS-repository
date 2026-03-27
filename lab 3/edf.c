#include <stdio.h>
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int arrival[n], burst[n], deadline[n], remaining[n];
printf("1bf24cs338 deepthi \n ");
    for(int i=0;i<n;i++){
        printf("Enter arrival time, burst time and deadline for process %d: ",i+1);
        scanf("%d %d %d",&arrival[i],&burst[i],&deadline[i]);
        remaining[i]=burst[i];
    }
    int time=0, completed=0;
    while(completed<n){
        int min_deadline=1000000000;
        int selected=-1;
        for(int i=0;i<n;i++){
            if(arrival[i]<=time && remaining[i]>0){
                if(deadline[i]<min_deadline){
                    min_deadline=deadline[i];
                    selected=i;
                }
            }
        }
        if(selected==-1){
            printf("%d ms : CPU is idle\n",time);
            time=time+1;
        }
        else{
            printf("%d ms : Task %d is running\n",time,selected+1);
            remaining[selected]=remaining[selected]-1;
            time=time+1;
            if(remaining[selected]==0){
                completed++;
            }
        }
    }
    return 0;
}
