#include <stdio.h>
#include<sys/stat.h>
#include <time.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    int iFD = 0;
    struct stat sObj = {0};

    if (argc != 2)
    {
        printf("Invalid Arguments.\n");
        printf("<Execution File> <File Name>\n");
        return -1;
    }

    stat(argv[1],&sObj);

    printf("File Name : %s\n",argv[1]);
    printf("INode Number : %d\n",sObj.st_ino);
    printf("File Size : %d\n",sObj.st_size);
    printf("Create Time : %s", asctime(gmtime(&sObj.st_ctime)));
    printf("Access Time : %s", asctime(gmtime(&sObj.st_atime)));
    printf("Modify Time : %s", asctime(gmtime(&sObj.st_mtime)));
    printf("Number of links : %d\n", sObj.st_nlink);
    printf("File systems number : %d\n", sObj.st_dev);

    return 0;
}