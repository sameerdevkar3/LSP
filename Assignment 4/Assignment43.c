#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int iFD1 = 0, iFD2 = 0, iRead = 0;
    char cBuffer1[BUFFERSIZE] = {0};
    char cBuffer2[BUFFERSIZE] = {0};
    struct stat sObj1 = {0}, sObj2 = {0};

    if (argc != 3)
    {
        printf("Invalid Argument.\n");
        return -1;
    }

    iFD1 = open(argv[1], O_RDONLY);
    iFD2 = open(argv[2], O_RDONLY);

    fstat(iFD1, &sObj1);
    fstat(iFD1, &sObj2);

    if(sObj1.st_size != sObj2.st_size)
    {
        printf("Files are differents.\n");
        return 0;
    }

    while ((iRead = read(iFD1, cBuffer1, BUFFERSIZE)) != 0)
    {
        iRead = read(iFD2, cBuffer2, BUFFERSIZE);
        if(memcmp(cBuffer1,cBuffer2,iRead) != 0)
        {
            break;
        }
    }

    if(iRead == 0)
    {
        printf("Files are Same.\n");
    }
    else
    {
        printf("Files are different.\n");
    }
    return 0;
}