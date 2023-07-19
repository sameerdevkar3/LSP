#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int iFD = 0;

    if (argc != 3)
    {
        printf("Invalid Arguments.\n");
        printf("<Execution File> <File Name> <String>\n");
        return -1;
    }
    iFD = open(argv[1], O_WRONLY);
    if (iFD == -1)
    {
        iFD = creat(argv[1],0777);
    }
    write(iFD,argv[2],sizeof(argv[2]));
    
    printf("successfully write in %s file\n", argv[1]);
    
    close(iFD);

    return 0;
}