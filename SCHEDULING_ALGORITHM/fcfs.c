#include<stdio.h>
int main()
{
	int i,j,burst=0, n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int prc[n], Bt[n], At[n];
	printf("Enter the process number, Arrival time & burst time: \nPNo\tAT\tBT\n");
	for(i=0;i<n;i++)
		scanf("%d%d%d",&prc[i],&At[i],&Bt[i]);


	int t,pos;
	for(i=0;i<n;i++)
	{
	pos = i;
		for(j=i+1;j<n;j++)
		{
			if(At[j]<At[pos])
				pos = j;
		}
//Swapping 
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
	

	printf("\nPno\tBT\tAT\tWT\tTA");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\n",prc[i],Bt[i],At[i],Wt[i],Ta[i]);
	}
	
//Finding Average waiting time	
	int sumwt=0;
	for(i=0;i<n;i++)
	{
		sumwt+=Wt[i];
	}
	float avgwt=(float)sumwt/(float)n;
	
//Finding Average Turn Around time
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
2 2 5
3 3 5

Pno     BT      AT      WT      TA
2       5       2       2       3

1       4       3       2       6

3       5       3       6       11

Average Waiting Time = 3.333333 milliseconds
Average Turnaround time = 6.666667 milliseconds */
