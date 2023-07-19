#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int iFD = 0;
    int iRead = 0;

    char cBuffer[BUFFERSIZE] = {0};

    if (argc != 2)
    {
        printf("Invalid Arguments.\n");
        printf("<Execution File> <File Name>\n");
        return -1;
    }

    iFD = open(argv[1], O_RDONLY);
    if (iFD == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((iRead = read(iFD, cBuffer, sizeof(cBuffer))) != 0)
    {
        write(1, cBuffer, iRead);
        memset(cBuffer, 0, iRead);
    }

    close(iFD);

    return 0;
}