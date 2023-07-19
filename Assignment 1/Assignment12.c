#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int iFD = 0;
    int iMode = 0;

    if (argc != 3)
    {
        printf("Invalid Arguments.\n");
        printf("<Execution File> <File Name> <Mode>\n");
        return -1;
    }

    if (strcmp(argv[2], "read"))
    {
        iMode = O_RDONLY;
    }
    else if (strcmp(argv[2], "write"))
    {
        iMode = O_WRONLY;
    }
    else if (strcmp(argv[2], "append"))
    {
        iMode = O_APPEND;
    }

    iFD = open(argv[1], iMode);
    if (iFD == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("%s file open successfully with mode %s and file descriptor is %d", argv[1], argv[2], iFD);
    close(iFD);

    return 0;
}