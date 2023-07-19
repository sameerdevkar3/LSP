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
    printf("\tFile name\tFile type\n");

    char cBuffer[128] = {0};
    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(cBuffer, "%s/%s", argv[1], entry->d_name);
        stat(cBuffer, &sObj);
        if (S_ISREG(sObj.st_mode))
        {
            memset(cBuffer, 0, sizeof(cBuffer));
            memcpy(cBuffer, "Regular File", 12);
        }
        else if (S_ISDIR(sObj.st_mode))
        {
            memset(cBuffer, 0, sizeof(cBuffer));
            memcpy(cBuffer, "Directory File", 14);
        }
        printf("%20s : %s\n", entry->d_name, cBuffer);
    }
    closedir(dp);
    return 0;
}