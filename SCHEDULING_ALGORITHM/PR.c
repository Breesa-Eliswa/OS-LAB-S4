#include<stdio.h>
int main()
{
	int i,j,burst=0, n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int prc[n], Bt[n], At[n], pr[n];
	printf("Enter the process number, Arrival time, priority & burst time: \nPNo\tAT\tPr\tBT\n");
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&prc[i],&At[i],&pr[i],&Bt[i]);


	int t,pos;
	for(i=0;i<n;i++)
	{
	pos = i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
				pos = j;
		}

	t=Bt[i];
	Bt[i]=Bt[pos];
	Bt[pos]=t;
	
	t=pr[i];
	pr[i]=pr[pos];
	pr[pos]=t;
	
	t=At[i];
	At[i]=At[pos];
	At[pos]=t;
	
	t=prc[i];
	prc[i]=prc[pos];
	prc[pos]=t;
	}		

	int Wt[n];
	for(int i=0;i<n;i++)
	{	
	if(i==0)
	{
		Wt[i]=At[i];
	}
	else
	{
		Wt[i]=burst-At[i];
	}
	burst+= Bt[i];
	}
	

	int Ta[n];
	int temp=0;
	for(int i=0;i<n;i++)
	{
		temp+=Bt[i];
		Ta[i]=temp-At[i];
	}
	

	printf("\nPno\tBT\tAT\tpr\tWT\tTA");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",prc[i],Bt[i],At[i],pr[i],Wt[i],Ta[i]);
	}
	
	
	int sumwt=0;
	for(i=0;i<n;i++)
	{
		sumwt+=Wt[i];
	}
	float avgwt=(float)sumwt/(float)n;
	

	int sumta=0;
	for(i=0;i<n;i++)
	{
		sumta+=Ta[i];
	}
	float avgta=(float)sumta/(float)n;
	
	printf("\nAverage Waiting Time = %f milliseconds\nAverage Turnaround time = %f milliseconds\n",avgwt,avgta);
	
	return 0;
}

/* OUTPUT
Enter the number of processes : 3
Enter the process number, Arrival time, priority & burst time: 
PNo     AT      Pr      BT
1 2 3 4
2 3 2 5
3 2 1 2

Pno     BT      AT      pr      WT      TA
3       2       2       1       2       0

2       5       3       2       -1      4

1       4       2       3       5       9

Average Waiting Time = 2.000000 milliseconds
Average Turnaround time = 4.333333 milliseconds */
