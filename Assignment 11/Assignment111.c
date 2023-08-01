#include <stdio.h>
#include <pthread.h>

void *ProcFunction(void *ptr)
{
    printf("%d : Jay Ganesh...!\n",(int)ptr);
    pthread_exit(0);
}

int main()
{
    int iRet[4] = {0}, iCnt = 0;
    pthread_t TID[4] = {0};

    for (iCnt = 0; iCnt < 4; iCnt++)
    {
        iRet[iCnt] = pthread_create(&TID[iCnt], NULL, ProcFunction, iCnt + 1);
        if (iRet[iCnt] == -1)
        {
            break;
        }
    }
    if (iCnt < 4)
    {
        printf("Unable to create four threads");
        return -1;
    }

    for (iCnt = 0; iCnt < 4; iCnt++)
    {
        pthread_join(TID[iCnt],NULL);
    }
    return 0;
}