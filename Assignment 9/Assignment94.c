#include <stdio.h>
#include <sys/resource.h>

int main()
{
    int iRet = 0;

    iRet = nice(-5);

    printf("Priority of process %d\n",iRet);
    
    return 0;
}