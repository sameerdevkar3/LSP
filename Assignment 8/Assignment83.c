#include <stdio.h>
#include <unistd.h>

int main()
{
    int iPD2 = 0, iPD3 = 0, iPD4 = 0,iStatus = 0;
    
    iPD2 = fork();
    if (iPD2 == 0 )
    {
        execl("ChildProcess",NULL,NULL);
    }

    iPD3 = fork();
    if (iPD3 == 0)
    {
        execl("ChildProcess", NULL, NULL);
    }

    iPD4 = fork();
    if (iPD4 == 0)
    {
        execl("ChildProcess", NULL, NULL);
    }
    return 0;
}