#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int iFD = 0, iMode = 0;
    ;

    if (argc != 3)
    {
        printf("Invalid Arguments.\n");
        return -1;
    }

    if (strcmp(argv[2], "read") == 0)
    {
        iMode = R_OK;
    }
    else if (strcmp(argv[2], "write") == 0)
    {
        iMode = W_OK;
    }
    else if (strcmp(argv[2], "execute") == 0)
    {
        iMode = X_OK;
    }

    if (access(argv[1], iMode) < 0)
    {
        printf("Unbale to access %s file in %s mode.\n", argv[1], argv[2]);
    }
    else
    {
        printf("You can access %s file in %s mode.\n", argv[1], argv[2]);
    }

    return 0;
}