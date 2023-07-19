#include<stdio.h>

int main(int argc,char* argv[])
{
    int iDIR = 0;
    if(argc != 2)
    {
        printf("Invalid Argument.\n");
        return -1;
    }
    iDIR = mkdir(argv[1]);

    if(!iDIR)
        printf("create directory succesfully.\n");
    else
        printf("Dose not create or already exists directory.\n");

    return 0;
}