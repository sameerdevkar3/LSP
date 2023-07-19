#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#pragma pack(1)
struct FileInfo
{
    char cName[24];
    unsigned int iSize;
};

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sObj = {0};
    char cPath[32] = {0};
    char cBuffer[1024] = {0};
    int iFD = 0, iRead = 0, iFDWrite = 0;
    struct FileInfo objFileInfo = {0};

    if (argc != 2)
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

    iFDWrite = creat("AllCombine.txt", 0777);

    if (iFDWrite == -1)
    {
        printf("Unable to create file.\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(cPath, "%s/%s", argv[1], entry->d_name);
        stat(cPath, &sObj);
        if (S_ISREG(sObj.st_mode))
        {
            strcpy(objFileInfo.cName, entry->d_name);
            objFileInfo.iSize = sObj.st_size;
            write(iFDWrite, &objFileInfo, sizeof(objFileInfo));
            iFD = open(cPath, O_RDONLY);

            while ((iRead = read(iFD, cBuffer, 1024)) != 0)
            {
                write(iFDWrite, cBuffer, iRead);
            }
        }
    }

    closedir(dp);
    close(iFDWrite);

    return 0;
}