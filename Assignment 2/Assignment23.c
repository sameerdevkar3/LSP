#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

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
    printf("\tFile name\n");

    while ((entry = readdir(dp)) != NULL)
    {
        printf("%20s\n", entry->d_name);
    }
    closedir(dp);

    closedir(dp);           
    return 0;
}