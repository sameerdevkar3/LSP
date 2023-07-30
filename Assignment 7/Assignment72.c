#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

int main()
{
    void *ptr = NULL;
    bool (*fptr)(char*,char*);

    ptr = dlopen("./Assignment72.so", RTLD_LAZY);

    if (ptr == NULL)
    {
        printf("Unable to load library.\n");
        return -1;
    }

    fptr = dlsym(ptr, "CheckSameFile");
    
    if (fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    if(fptr("Assignment71.c","Assignment72.c"))
        printf("File is Same.\n");
    else    
        printf("File are different.\n");

    return 0;
}