#include <stdio.h>
#include<stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int iFD = 0;
    int iRead = 0;

    char *pBuffer = NULL;

    if (argc != 3)
    {
        printf("Invalid Arguments.\n");
        printf("<Execution File> <File Name> <Read Count\n");
        return -1;
    }
    int iSize = atoi(argv[2]);
    pBuffer = (char *)malloc(iSize);

    iFD = open(argv[1], O_RDONLY);
    if (iFD == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((iRead = read(iFD, pBuffer, iSize)) != 0)
    {
        write(1, pBuffer, iRead);
        memset(pBuffer,0,iRead);
    }

    close(iFD);
    free(pBuffer);

    return 0;
}