#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int iFD = 0, iRead = 0;
    char cStr[20] = {0};

    if (argc != 3)
    {
        printf("Invalid Arguments.\n");
        return -1;
    }
    iFD = open(argv[1], O_RDONLY);
    if (iFD == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }
    lseek(iFD, atoi(argv[2]), 0);
    iRead = read(iFD, cStr, 20);

    printf("data from file is \n");
    write(1, cStr, iRead);
    return 0;
}