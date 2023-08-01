#include <stdio.h>
#include <pthread.h>

void* ProcFunction(void* ptr)
{
    printf("Jay Ganesh...! ---> %s\n",(char*)ptr);
    pthread_exit(0);
}


int main()
{
    pthread_t TID = 0;
    int iRet = 0;

    iRet = pthread_create(&TID,NULL,ProcFunction,(char*)"Marvellous");
    if(iRet == -1)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,NULL);
    return 0;
}