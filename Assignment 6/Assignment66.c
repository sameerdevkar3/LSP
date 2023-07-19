#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void createHole(char *pName,int iSize)
{
    int iFD = open(pName,O_WRONLY);
    lseek(iFD, 1023-iSize, 2);
    write(iFD, "z", 1);
    close(iFD);
}

void trucateFile(char* pName)
{
    truncate(pName,1024);
}

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sObj = {0};
    char cPath[32] = {0};

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

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(cPath, "%s/%s", argv[1], entry->d_name);
        stat(cPath, &sObj);
        if (sObj.st_size < 1024)
        {
            createHole(cPath, sObj.st_size);
        }
        else
            trucateFile(cPath);
        memset(cPath, 0, 32);
    }

    closedir(dp);

    return 0;
}