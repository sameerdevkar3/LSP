#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int iPipe = 0, iFD = 0,iRet = 0;
    char *pName = "/tmp/queue-tmp";

    iPipe = mkfifo(pName, 0777);
    if (iPipe == -1)
    {
        printf("Unable to create pipe.\n");
        return -1;
    }

    iFD = open(pName, O_WRONLY);
    if(iFD == -1)
    {
        printf("Unable to open pipe\n");
        return -1;
    }
    iRet = write(iFD,"Jay Ganesh...!",14);
    if(iRet == 14)
    {
        printf("Successfully write data on pipe\n");
    }
    else
    {
        printf("Unsuccessfully write data on pipe\n");
    }
    return 0;
}