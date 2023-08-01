#include <stdio.h>
#include <pthread.h>

#define MAXTHREAD 10

void *ProcFunction(void *ptr)
{
    pthread_mutex_t lock;
    pthread_mutex_lock(&lock);
    printf("Common variable : %d\n",++(*((int*)ptr)));
    pthread_mutex_unlock(&lock);
    pthread_exit(0);
}

int main()
{
    int iRet[MAXTHREAD] = {0}, iCnt = 0;
    pthread_t TID[MAXTHREAD] = {0};
    int iCommonValue = 11;

    for (iCnt = 0; iCnt < MAXTHREAD; iCnt++)
    {
        iRet[iCnt] = pthread_create(&TID[iCnt], NULL, ProcFunction, &iCommonValue);
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

    for (iCnt = 0; iCnt < MAXTHREAD; iCnt++)
    {
        pthread_join(TID[iCnt],NULL);
    }
    return 0;
}