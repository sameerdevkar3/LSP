#include <stdio.h>
#include <pthread.h>

void* ProcFunction1(void*)
{
    for(int i = 1;i <= 500;i++)
    {
        printf("thread 1 : %d\n",i);
    }
    pthread_exit(0);
}

void* ProcFunction2(void*)
{
    for(int i = 500;i >= 1 ;i--)
    {
        printf("thread 2 : %d\n",i);
    }
    pthread_exit(0);
}

int main()
{
    pthread_t TID1 = 0,TID2 = 0;
    int iRet1 = 0,iRet2 = 0;

    iRet1 = pthread_create(&TID1,NULL,ProcFunction1,NULL);
    if(iRet1 == -1)
    {
        printf("Unable to create thread 1\n");
        return -1;
    }

    iRet2 = pthread_create(&TID2,NULL,ProcFunction2,NULL);
    if(iRet2 == -1)
    {
        printf("Unable to create thread 2\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    return 0;
}