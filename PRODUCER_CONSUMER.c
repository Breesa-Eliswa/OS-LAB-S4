#include<stdio.h>
#include<stdlib.h>

void producer();

void consumer();

int wait(int s);

int signal1(int s);

int mutex =1 , full =0 , empty = 5 , x =0 , ch;

int main()
{
    printf("\n 1.PRODUCER \n 2.CONSUMER \n 3.EXIT");
    do
    {
        printf("\nEnter the choice: \n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if((mutex==1)&&(empty!=0))
                producer();
            else
                printf("Buffer is full!!..");
            break;
            
            case 2:
            if((mutex==1)&&(full!=0))
                consumer();
            else
                printf("Buffer is empty!!..");
            break;
            
            case 3:
                printf("Going to Exit!!..");
                break;
            default:
                printf("Invalid entry!!");
            
        }
    }while(ch!=3);
}

int wait(int s)
{
    return(--s);
}

int signal1(int s)
{
    return(++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal1(full);
    empty = wait(empty);
    x++;
    printf("Producer produces the item %d",x);
    mutex = signal1(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal1(empty);
    printf("Consumer consumes the item %d",x);
    x--;
    mutex = signal1(mutex);
}

/* output:
1.PRODUCER 
 2.CONSUMER 
 3.EXIT
Enter the choice: 
 1
Producer produces the item 1
Enter the choice: 
 1
Producer produces the item 2
Enter the choice: 
 4
Invalid entry!!
Enter the choice: 
 2
Consumer consumes the item 2
Enter the choice: 
 3
Going to Exit!!..
*/



