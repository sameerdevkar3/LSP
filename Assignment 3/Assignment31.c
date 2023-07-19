#include <stdio.h>
#include<fcntl.h>
#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int fdRead = 0,fdWrite = 0,iRead = 0;
    char cBuffer[BUFFERSIZE] = {0};
    
    if(argc != 3)
    {
        printf("Invalid Arguments.\n");
        printf("<Executable File> <Source File> <Destination File>\n");
    }

    fdRead = open(argv[1],O_RDONLY);

    if(fdRead == -1)
    {
        printf("Unbale to open source file.\n");
        return -1;
    }

    fdWrite = creat(argv[2],0777);

    if(fdWrite == -1)
    {
        printf("Unable tp create destination file.\n");
        return -1;
    }

    while((iRead = read(fdRead,cBuffer,BUFFERSIZE)) != 0)
    {
        write(fdWrite,cBuffer,iRead);
    }

    close(fdRead);
    close(fdWrite);
    return 0;
}