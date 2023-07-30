#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int iPD2 = 0, iPD3 = 0, iStatus2 = 0, iStatus3 = 0;


    iPD2 = fork();
    if (iPD2 == 0)
    {
        execl("ChildProcess",NULL,NULL);
    }
    else
    {
        wait(&iStatus2);
    }
    iPD3 = fork();
    if (iPD3 == 0)
    {
        execl("ChildProcess",NULL,NULL);
    }

    else
    {
        wait(&iStatus3);
    }
    return 0;
}