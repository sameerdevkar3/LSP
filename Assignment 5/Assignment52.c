#include <stdio.h>
#include <fcntl.h>

#pragma pack(1)
struct Employee
{
    int iEmployeeNumber;
    char cName[20];
    unsigned short iAge;
};

int main(int argc, char *argv[])
{
    struct Employee objEmployee = {0};
    int iFD = 0, iRead = 0;

    if (argc != 2)
    {
        printf("Invalid Arguments.\n");
        return -1;
    }

    iFD = open(argv[1], O_RDONLY);

    while ((iRead = read(iFD, &objEmployee, sizeof(objEmployee))) != 0)
    {
        printf("Empolyee Id : %d\n", objEmployee.iEmployeeNumber);
        printf("Employee Name : %s\n", objEmployee.cName);
        printf("Employee Age : %d\n", objEmployee.iAge);
        memset(&objEmployee, 0, sizeof(objEmployee));
    }

    return 0;
}
