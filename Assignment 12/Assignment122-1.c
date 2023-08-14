#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int Shmid = 0, iKey = 2327, iShmSize = 10;
    char *ptrSHM = NULL;

    Shmid = shmget(iKey, iShmSize, IPC_CREAT | 0666);
    if (!Shmid)
    {
        printf("Shared memory can't allocated memory\n");
        return -1;
    }

    ptrSHM = shmat(Shmid, NULL, 0);

    if (ptrSHM)
    {
        printf("Succesfully attach to shared memory...\n");
    }

    memcpy(ptrSHM,"Jay Ganesh...!",14);
    ptrSHM = ptrSHM + 14;
    *ptrSHM = '\0';

    return 0;
}