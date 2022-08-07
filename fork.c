/* Write a program to create 2 process. One parent process must add numbers upto limit n at the same time the child process must add even numbers upto n , also print the process id 
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    int sumodd=0 , sumeven=0 , num ,i;
    printf("Enter the number limit\n");
    scanf("%d",&num);
    if(fork()>0)
    {
        for(i=1;i<=num;i=i+2)
            sumodd = sumodd+i;
        printf("\nParent Process\n");
        printf("Sum of odd numbers is %d\n",sumodd);
        printf("The parent id is %d\n ",getppid());
    }
    else
    {
        for(i=0;i<=num;i=i+2)
            sumeven = sumeven+i;
        printf("\nChild process\n");
        printf("Sum of even numbers is %d \n ",sumeven);
        printf("The child id is %d \n",getpid());
    }
}
/* OUTPUT
Enter the number limit
15

Parent Process
Sum of odd numbers is 64
The parent id is 1167

 Child process
Sum of even numbers is 56 
 The child id is 1172  */
