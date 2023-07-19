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
    char cBuffer[1024] = {0};
    int iFD = 0, iRead = 0;

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
        if (S_ISREG(sObj.st_mode))
        {
            printf("File name : %s\n", entry->d_name);
            printf("File size is : %d\n", sObj.st_size);
            printf("Number of links : %d\n", sObj.st_nlink);
            printf("Inode number : %d\n", sObj.st_ino);
            printf("File systems number : %d\n", sObj.st_dev);

            iFD = open(cPath,O_RDONLY);

            while ((iRead = read(iFD,cBuffer,1024)) != 0)
            {
                write(1,cBuffer,iRead);
            }
            
        }
    }

    closedir(dp);
    return 0;
}