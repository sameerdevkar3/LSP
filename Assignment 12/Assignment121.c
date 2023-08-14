#include<stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int iPID = 0,iPipe = 0,iStatus = 0;
    int iArr[2] = {0};
    char cBuff[16] = {0};
    char* pBuffer = "Jay Ganesh...!";

    iPipe = pipe(iArr);
    if(iPipe == -1)
    {
        printf("Unable to create pipe.\n");
        return -1;
    }

    iPID = fork();
    if(iPID == 0)
    {
        close(iArr[1]);
        
        read(iArr[0],cBuff,sizeof(cBuff));
        write(1,cBuff,sizeof(cBuff));
        write(1,"\n",1);
        close(iArr[1]);
    }
    else if (iPID == -1)
    {
        printf("Unable to create child process.\n");
        return -1;
    }
    else
    {
        close(iArr[0]);
        write(iArr[1], pBuffer, strlen(pBuffer));
        close(iArr[1]);
        wait(&iStatus);
    }
    return 0;
}