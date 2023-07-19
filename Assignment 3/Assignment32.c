#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    struct DIR *dp = NULL;
    struct dirent *entry = NULL;

    if (argc != 3)
    {
        printf("Invalid Arguments.\n");
        printf("<Executable File> <directory Name> <File Name>\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if (!dp)
    {
        printf("Unbale to open directory.\n");
        return -1;
    }

    bool bFlag = false;
    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(argv[2], entry->d_name) == 0)
        {
            bFlag = true;
            break;
        }
    }

    if (bFlag)
    {
        printf("File is Found.\n");
    }
    else
    {
        printf("File is not Found.\n");
    }

    return 0;
}