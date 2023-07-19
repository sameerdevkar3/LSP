#include <stdio.h>
#include <fcntl.h>

#pragma pack(1)
struct FileInfo
{
    unsigned int iSize;
    char cName[16];
};


int main(int argc,char* argv[])
{
    int iFD = 0,iRead = 0;
    struct FileInfo objFileInfo = {0};
    if(argc != 3)
    {
        printf("Invalid Arguments.\n");
        return -1;
    }

    iFD = open(argv[1],O_RDONLY);
    if(iFD == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }

    printf("File Name is greater than %s :",argv[2]);
    while ((iRead = read(iFD,&objFileInfo,sizeof(objFileInfo))) != 0)
    {
        if(atoi(argv[1]) < objFileInfo.iSize)
        {
            printf("%s\n",objFileInfo.cName);
        }
    }
    return -1;
}