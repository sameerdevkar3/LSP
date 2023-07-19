#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct stat sObj = {0};
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    if (argc != 2)
    {
        printf("Invalid Arguments.\n");
        printf("<Execution File> <Directory Name>\n");
        return -1;
    }
    stat(argv[1], &sObj);
    if (!S_ISDIR(sObj.st_mode))
    {
        printf("%s is not directory\n", argv[1]);
        return -1;
    }
    dp = opendir(argv[1]);
    if (!dp)
    {
        printf("Unable to open directory.\n");
        return -1;
    }

    char cBuffer[128] = {0}, FileName[255] = {0};
    int iMaxSize = 0;
    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(cBuffer, "%s/%s", argv[1], entry->d_name);
        stat(cBuffer, &sObj);
        if (S_ISREG(sObj.st_mode))
        {
            if (iMaxSize < sObj.st_size)
            {
                iMaxSize = sObj.st_size;
                memset(FileName, 0, sizeof(FileName));
                memcpy(FileName, entry->d_name, sizeof(entry->d_name));
            }
        }
    }
    printf("Largest File is : %s\n", FileName);
    closedir(dp);
    return 0;
}