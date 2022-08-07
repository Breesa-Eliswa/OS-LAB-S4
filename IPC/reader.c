// Program to read data from the shared memory 
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
int main()
{
    int shmid;
    void *shared_memory;
    char buff[200];
    shmid =shmget((key_t)2345,1024,0666);
    printf("Key of the shared memory is %d",shmid);
    shared_memory =shmat(shmid,NULL,0);
    printf("Process is attached at %p",shared_memory);
    printf("Data read from shared memory is: %s",(char*)shared_memory);
}
