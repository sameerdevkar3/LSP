#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

int main()
{
    void *ptr1 = NULL;
    unsigned int (*fptr1)(int);

    int iValue = 6;

    ptr1 = dlopen("./OuterLibrary.so", RTLD_LAZY);

    if (ptr1 == NULL)
    {
        printf("Unable to load library.\n");
        return -1;
    }

    fptr1 = dlsym(ptr1, "loadFactLib");

    if (fptr1 == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    printf("factorial of %d is %d\n",iValue,fptr1(iValue));
    return 0;
}