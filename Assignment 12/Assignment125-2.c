#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int iFD = 0, iRet = 0;
    char *pName = "/tmp/queue-tmp";
    char cBuffer[32] = {0};

    iFD = open(pName, O_RDONLY);
    if (iFD == -1)
    {
        printf("Unable to open pipe\n");
        return -1;
    }
    iRet = read(iFD, cBuffer, sizeof(cBuffer));
    
    write(1,cBuffer,iRet);
    write(1,"\n",1);

    return 0;
}