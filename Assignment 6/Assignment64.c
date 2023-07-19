#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sObj = {0};
    char cPath[32] = {0};

    if (argc != 3)
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
        if (sObj.st_size == 100)
        {
            remove(cPath);
        }
        memset(cPath, 0, 32);
    }

    printf("Succesfully delete all files whose size is %d.\n",argv[2]);

    closedir(dp);

    return 0;
}