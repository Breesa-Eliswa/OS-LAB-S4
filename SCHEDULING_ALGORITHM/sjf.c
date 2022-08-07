#include<stdio.h>
int main()
{
	int i,n,pos,j,t;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int prc[n], Bt[n], At[n];
	printf("Enter the process number, Arrival time & burst time: \nPNo\tAT\tBT\n");
	for(i=0;i<n;i++)
		scanf("%d%d%d",&prc[i],&At[i],&Bt[i]);
		

	for(i=0;i<n-1;i++)
	{
	pos = i;
		for(j=i+1;j<n;j++)
		{
			if(Bt[j]<Bt[pos])
				{
				pos = j;
				}
		}

	t=Bt[i];
	Bt[i]=Bt[pos];
	Bt[pos]=t;
	
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
		Wt[i]=0;
	}
	else
	{
		Wt[i] =  Bt[i-1] + Wt[i-1] ;
	}
	}
	
	
	int Ta[n];
	for(int i=0;i<n;i++)
	{
		Ta[i]=Bt[i]+At[i];
	}

	printf("\nPno\tBT\tAT\tWT\tTA");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\n",prc[i],Bt[i],At[i],Wt[i],Ta[i]);
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
Enter the process number, Arrival time & burst time: 
PNo     AT      BT
1 3 4
2 2 2
3 4 3

Pno     BT      AT      WT      TA
2       2       2       0       4

3       3       4       2       7

1       4       3       5       7

Average Waiting Time = 2.333333 milliseconds
Average Turnaround time = 6.000000 milliseconds */
