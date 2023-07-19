#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int iRet = 0;
    if (argc != 3)
    {
        printf("Invalid Arguments.\n");
        return -1;
    }

    iRet = truncate(argv[1], atoi(argv[2]));
    if (!iRet)
        printf("delete data from %d offset.\n", argv[2]);
    return 0;
}