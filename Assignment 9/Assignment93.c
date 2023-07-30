#include <stdio.h>
#include <sys/resource.h>

int main()
{
    int iRet = 0;

    iRet = getpriority(PRIO_PROCESS,0);

    printf("Priority of process %d\n",iRet);

    return 0;
}