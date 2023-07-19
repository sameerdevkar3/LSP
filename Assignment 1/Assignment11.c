#include<stdio.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
    int iFD = 0;
    if(argc != 2)
    {
        printf("Invalid Arguments.\n");
        printf("<Execution File> <File Name>\n");
        return -1;
    }

    iFD = open(argv[1],O_RDONLY);
    if(iFD == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("File open successfully with file descriptor : %d",iFD);
    close(iFD);

    return 0;
}