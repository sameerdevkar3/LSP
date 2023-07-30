#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int iPD = 0, iStatus = 0;

    iPD = fork();

    if (iPD == 0)
    {
        execl("ChildProcess",NULL,NULL);
    }
    else
    {
        wait(&iStatus);
        printf("End Parent Process.\n");
    }
    return 0;
}