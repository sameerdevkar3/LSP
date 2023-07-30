#include <stdio.h>
#include <sched.h>

int main()
{
    int iRet = 0;

    iRet = sched_yield();

    if(!iRet)
        printf("Sucessfully yield process\n");
    
    return 0;
}