#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

int main()
{
    void *ptr1 = NULL;
    void *ptr2 = NULL;
    bool (*fptr1)(int);
    bool (*fptr2)(int);

    int iValue = 6;

    ptr1 = dlopen("./Prime.so", RTLD_LAZY);
    ptr2 = dlopen("./Perfect.so", RTLD_LAZY);

    if (ptr1 == NULL)
    {
        printf("Unable to load library.\n");
        return -1;
    }

    fptr1 = dlsym(ptr1, "Prime");
    fptr2 = dlsym(ptr2, "Perfect");

    if (fptr1 == NULL || fptr2 == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    if (fptr1(iValue))
        printf("Number is prime.\n");
    else
        printf("Number is not prime.\n");

    if (fptr2(iValue))
        printf("Number is perfect.\n");
    else
        printf("Number is not perfect.\n");

    return 0;
}