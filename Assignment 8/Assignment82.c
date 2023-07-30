#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int iPD1 = 0, iPD2 = 0,iStatus = 0;
    iPD1 = fork();

    if (iPD1 == 0)
    {
        execl("Process2",NULL,NULL);
    }
    else
    {
        wait(&iStatus);
        printf("End Of Process 1\n");
    }
    return 0;
}