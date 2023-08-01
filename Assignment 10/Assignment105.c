#include <stdio.h>
#include <pthread.h>

void* ProcFunction(void* ptr)
{
    pthread_exit(pthread_self());
}


int main()
{
    pthread_t TID = 0;
    int iRet = 0;
    pthread_t TRet = 0;

    iRet = pthread_create(&TID,NULL,ProcFunction,(int*)11);
    if(iRet == -1)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,&TRet);

    printf("Recevied from thread : %ld\n",TRet);
    return 0;
}