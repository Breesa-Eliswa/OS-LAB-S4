// Program to write data to the shared memory 
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
int main()
{
    int shmid;
    void *shared_memory;
    char buff[200];
    shmid =shmget((key_t)2345,1024,0666|IPC_CREAT);
    printf("Key of the shared memory is %d",shmid);
    shared_memory =shmat(shmid,NULL,0);
    printf("\nProcess is attached at %p",shared_memory);
    printf("\nEnter some data to write in shared memory\n");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("The data written to the memory is : \n %s",(char*)shared_memory);
}

/* OUTPUT
Key of the shared memory is 0
Process is attached at 0x7fae8d61d000
Enter some data to write in shared memory
Hello World!!...
The data written to the memory is : 
 Hello World!!...    */
