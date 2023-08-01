#include <stdio.h>
#include <pthread.h>

void* ProcFunction(void*)
{
    printf("Jay Ganesh...!\n");
    pthread_exit(0);
}


int main()
{
    pthread_t TID = 0;
    int iRet = 0;

    iRet = pthread_create(&TID,NULL,ProcFunction,NULL);
    if(iRet == -1)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,NULL);
    return 0;
}