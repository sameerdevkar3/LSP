#include <stdio.h>
#include <pthread.h>

void* ProcFunction(void* ptr)
{
    int iValue = (int)ptr;
    printf("Recevied from main : %d\n",iValue);
    pthread_exit(iValue + 10);
}


int main()
{
    pthread_t TID = 0;
    int iRet = 0,TRet = 0;

    iRet = pthread_create(&TID,NULL,ProcFunction,(int*)11);
    if(iRet == -1)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,&TRet);

    printf("Recevied from thread : %d\n",TRet);
    return 0;
}