#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int iPD1 = 0, iPD2 = 0, iStatus1 = 0, iStatus2 = 0;

    iPD1 = fork();
    if (iPD1 == 0)
    {
        execl("CountUpper", "NULL", "demo.txt", NULL);
    }
    else
    {
        wait(&iStatus1);
    }

    iPD2 = fork();
    if (iPD2 == 0)
    {
        execl("CountUpper", "NULL", "hello.txt", NULL);
    }
    else
    {
        wait(&iStatus2);
    }
    return 0;
}