#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *ptr1 = NULL;
    int (*fptr1)(int,int);
    int (*fptr2)(int,int);
    int (*fptr3)(int,int);
    int (*fptr4)(int,int);
    int iNo1 = 22;
    int iNo2 = 11;

    ptr1 = dlopen("./Assignment71.so", RTLD_LAZY);

    if (ptr1 == NULL)
    {
        printf("Unable to load library.\n");
        return -1;
    }

    fptr1 = dlsym(ptr1, "Addition");
    fptr2 = dlsym(ptr1, "Subtraction");
    fptr3 = dlsym(ptr1, "Multiplication");
    fptr4 = dlsym(ptr1, "Division");
    
    if (fptr1 == NULL || fptr2 == NULL || fptr3 == NULL || fptr4 == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    printf("%d + %d = %d\n",iNo1,iNo2,fptr1(iNo1,iNo2));
    printf("%d - %d = %d\n",iNo1,iNo2,fptr2(iNo1,iNo2));
    printf("%d * %d = %d\n",iNo1,iNo2,fptr3(iNo1,iNo2));
    printf("%d / %d = %d\n",iNo1,iNo2,fptr4(iNo1,iNo2));
    return 0;
}