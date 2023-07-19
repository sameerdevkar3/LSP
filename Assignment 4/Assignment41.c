#include<stdio.h>

int main(int argc,char* argv[])
{
    int iNo1 = 0,iNo2 = 0,iAns = 0;
    if(argc != 3)
    {
        printf("Invalid Argument.\n");
        return -1;
    }

    iNo1 = atoi(argv[1]);
    iNo2 = atoi(argv[2]);

    iAns = iNo1 + iNo2;

    printf("Addition : %d + %d = %d",iNo1,iNo2,iAns);
    
    return 0;
}