#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

#pragma pack(1)
struct FileInfo
{
    char cName[24];
    unsigned int iSize;
};

void readFile(char *Name, int iFDRead, int iSize)
{
    int iRead = 0;
    char *pBuffer = (char *)malloc(iSize);
    if (!pBuffer)
        printf("Unable allocate memory.\n");
    int iFDWrite = creat(Name, 0777);
    if (iFDWrite == -1)
    {
        printf("error file : %s\n", Name);
        return;
    }
    iRead = read(iFDRead, pBuffer, iSize);

    write(iFDWrite, pBuffer, iRead);
    free(pBuffer);
}

int main(int argc, char *argv[])
{
    int iFD = 0, iRead = 0;
    struct FileInfo objFileInfo = {0};

    if (argc != 2)
    {
        printf("Invalid Arguments.\n");
        return -1;
    }

    iFD = open(argv[1], O_RDONLY);
    if (iFD == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }
    while ((iRead = read(iFD, &objFileInfo, sizeof(objFileInfo)) != 0))
    {
        readFile(objFileInfo.cName, iFD, objFileInfo.iSize);
    }
    return 0;
}