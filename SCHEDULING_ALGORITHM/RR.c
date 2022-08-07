#include <stdio.h>

int main()
{
    int n,index,i,j,t,tot_wt=0,tot_tat=0,burst,temp,qt,flag=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int x=n;
    int p[n],at[n],bt[n],wt[n],tat[n],rt[n];
    printf("Enter process no,arrival time,burst time\n");
    printf("PNO\tAT\tBT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&p[i],&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    printf("Enter the quantum time:");
    scanf("%d",&qt);
    for(i=0,t=0;x!=0;)
    {
        if(rt[i]<=qt && rt[i]>0)
        {
            t+=rt[i];
            rt[i]=0;
            flag=1;
        }
        
        else if(rt[i]>0)
        {
            t+=qt;
            rt[i]-=qt;
        }
        
        if(flag==1 && rt[i]==0)
        {
            x--;
            p[j]=i+1;
            wt[j]=t-at[i]-bt[i];
            tat[j++]=t-at[i];
            flag=0;
        }
        
        if(i==n-1)
            i=0;
        else if(at[i+1]<=t)
            i++;
        else
            i=0;
    }
    
    printf("\nPNO\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    
    for(i=0;i<n;i++)
    {
        tot_wt+=wt[i];
        tot_tat+=tat[i];
    }    
    printf("\nAverage waiting time is %f\nAverage turn around time is %f\n",(float)tot_wt/(float)n,(float)tot_tat/(float)n);
}

/* OUTPUT
Enter number of processes: 3
Enter process no,arrival time,burst time
PNO     AT      BT
1 3 4
2 2 2
3 1 2
Enter the quantum time:2

PNO     AT      BT      WT      TAT
2       3       4       0       2
3       2       2       3       5
1       1       2       1       5

Average waiting time is 1.333333
Average turn around time is 4.000000 */






