#include <stdio.h>

int gcd(int a, int b)
{
    while(b)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int n;

    printf("Enter the number of processes:");
    scanf("%d",&n);

    int burst[n], period[n], remaining[n];

    printf("Enter the CPU burst times:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&burst[i]);

    printf("Enter the time periods:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&period[i]);

    int hyper = period[0];
    for(int i=1;i<n;i++)
        hyper = lcm(hyper, period[i]);

    printf("LCM=%d\n\n",hyper);

    printf("Rate Monotone Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",i+1,burst[i],period[i]);
        remaining[i] = 0;
    }

    float util = 0;
    for(int i=0;i<n;i++)
        util += (float)burst[i] / period[i];

    float bound;
    if(n == 2)
        bound = 0.828427;
    else
        bound = n * (pow(2.0,1.0/n)-1);

    printf("\n%f <= %f => %s\n",
           util,bound,
           (util <= bound) ? "true" : "false");

    printf("Scheduling occurs for %d ms\n\n",hyper);

    int last = -2;

    for(int time=0; time<hyper; time++)
    {
        for(int i=0;i<n;i++)
        {
            if(time % period[i] == 0)
                remaining[i] += burst[i];
        }

        int selected = -1;
        int minPeriod = 99999;

        for(int i=0;i<n;i++)
        {
            if(remaining[i] > 0 && period[i] < minPeriod)
            {
                minPeriod = period[i];
                selected = i;
            }
        }

        if(selected != last)
        {
            if(selected == -1)
                printf("%dms onwards: CPU is idle\n",time);
            else
                printf("%dms onwards: Process %d running\n",
                       time, selected+1);

            last = selected;
        }

        if(selected != -1)
            remaining[selected]--;
    }

    return 0;
}
