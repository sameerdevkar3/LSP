#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>

#define BUFFERSIZE 1024

void *ThreadProc1(void *ptr)
{
    char cBuffer[BUFFERSIZE] = {0};

    int iCnt = 0, iRead = 0, iFD = 0, i = 0;

    iFD = open("Demo.txt", O_RDONLY);

    while ((iRead = read(iFD, cBuffer, BUFFERSIZE)) != 0)
    {
        for (i = 0; i < iRead; i++)
        {
            if (cBuffer[i] >= 'A' && cBuffer[i] <= 'Z')
                iCnt++;
        }
    }

    printf("Number of capital letter is %d\n", iCnt);

    close(iFD);
    pthread_exit(0);
}

void *ThreadProc2(void *ptr)
{
    char cBuffer[BUFFERSIZE] = {0};

    int iCnt = 0, iRead = 0, iFD = 0, i = 0;

    iFD = open("Demo.txt", O_RDONLY);

    while ((iRead = read(iFD, cBuffer, BUFFERSIZE)) != 0)
    {
        for (i = 0; i < iRead; i++)
        {
            if (cBuffer[i] >= 'a' && cBuffer[i] <= 'z')
                iCnt++;
        }
    }

    printf("Number of small letter is %d\n", iCnt);

    close(iFD);
    pthread_exit(0);
}

int main()
{
    pthread_t TID1 = 0, TID2 = 0;
    int iRet1 = 0, iRet2 = 0;

    iRet1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    if (iRet1 != 0)
    {
        printf("Unable to create thread 1\n");
        return -1;
    }

    iRet2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);
    if (iRet2 != 0)
    {
        printf("Unable to create thread 2\n");
        return -1;
    }

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    pthread_exit(NULL);
    return 0;
}