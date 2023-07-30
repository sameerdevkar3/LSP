#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int iPD = 0,iStatus = 0;
    char *pPath = "/home/sameer/Desktop";

    iPD = fork();
    if(iPD == 0)
    {
        execl("ReadFileOnDesktop","NULL",pPath,NULL);
    }
    else
    {
        wait(&iStatus);
    }
   return 0;
}