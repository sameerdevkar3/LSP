#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char cPath[32] = {0};
    int iFD = 0;

    if (argc != 3)
    {
        printf("Invalid Argument.\n");
        return -1;
    }

    sprintf(cPath,"%s/%s",argv[1],argv[2]);
    iFD = creat(cPath, 0777);

    if (iFD == -1)
    {
        printf("Unable to create file.\n");
        return -1;
    }
    else
    {
        printf("Sicessfully create file.\n");
    }

    return 0;
}