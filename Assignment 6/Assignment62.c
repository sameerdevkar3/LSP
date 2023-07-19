#include <stdio.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
    int iFD = 0;
    if(argc != 3)
    {
        printf("Invalid Arguments.\n");
        return -1;
    }

    iFD = open(argv[1],O_WRONLY);
    if(iFD == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }

    lseek(iFD,atoi(argv[2]),2);
    
    write(iFD,"z",1);

    printf("Succesfully create hole of size %s in %s file.\n", argv[2], argv[1]);
    return 0;
}