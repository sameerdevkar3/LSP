#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int Shmid = 0, iKey = 2327, iShmSize = 10;
    char *ptrSHM = NULL;

    Shmid = shmget(iKey,iShmSize, 0666);

    ptrSHM = shmat(Shmid, NULL, 0);

    if (ptrSHM)
    {
        printf("Succesfully attach to shared memory...\n");
    }

    while (*ptrSHM != '\0')
    {
        printf("%c",*ptrSHM);
        ptrSHM++;
    }
    printf("\n");
    return 0;
}