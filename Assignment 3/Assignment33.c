#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dpSrc = NULL, *dpDst = NULL;
    struct dirent *entry = NULL;
    char cSrcPath[128] = {0};
    char cDstPath[128] = {0};

    if (argc != 3)
    {
        printf("Invalid Argument.\n");
        return -1;
    }

    dpSrc = opendir(argv[1]);

    if (!dpSrc)
    {
        printf("Unable to open directory.\n");
        return -1;
    }

    while ((entry = readdir(dpSrc)) != NULL)
    {
        sprintf(cSrcPath, "%s/%s", argv[1], entry->d_name);
        sprintf(cDstPath, "%s/%s", argv[2], entry->d_name);
        rename(cSrcPath, cDstPath);
    }

    printf("Succesfully move files or directory.\n");

    closedir(dpSrc);

    return 0;
}