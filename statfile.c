// TO DISPLAY THE STATUS OF A GIVEN FILE
#include<stdio.h>
#include<sys/stat.h>

void fileproperties(struct stat buf);

int main()
{
    char path[100];
    struct stat buf;
    printf("Enter the path of a file: ");
    scanf("%s",&path);
    stat(path,&buf);
    fileproperties(buf);
}
void fileproperties(struct stat buf)
{
    printf("\n Uid: %d",buf.st_uid);
    printf("\n Size:%d",buf.st_size);
}
