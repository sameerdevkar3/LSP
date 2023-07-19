#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sObj = {0};
    char cPath[32] = {0};
    char *pData = NULL;
    int iFD = 0, iRead = 0, iFDWrite = 0;

    if (argc != 4)
    {
        printf("Invalid Argument.\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if (!dp)
    {
        printf("Unable to open directory.\n");
        return -1;
    }

    iFDWrite = creat(argv[2], 0777);

    if(iFDWrite == -1)
    {
        printf("Unable to create file.\n");
        return -1;
    }

    pData = (char *)malloc(sizeof(atoi(argv[3])));

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(cPath, "%s/%s", argv[1], entry->d_name);
        stat(cPath, &sObj);
        if (S_ISREG(sObj.st_mode))
        {
            iFD = open(cPath, O_RDONLY);
            printf("%d\n", iFD);
            iRead = read(iFD, pData, atoi(argv[3]));
            write(iFDWrite, pData, iRead);
            write(1, pData, iRead);
            close(iFD);
            iFD = 0;
            memset(pData, 0, atoi(argv[3]));
        }
    }

    closedir(dp);
    close(iFDWrite);
    free(pData);

    return 0;
}