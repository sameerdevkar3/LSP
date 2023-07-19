#include <stdio.h>
#include <fcntl.h>

#pragma pack(1)
struct Student
{
    int iRollNumber;
    char cName[20];
    float fMarks;
    unsigned short iAge;
};

int main(int argc,char* argv[])
{
    struct Student objStudent = {0};
    int iFD = 0;

    iFD = open("Test.txt",0777);

    objStudent.iRollNumber = 1;
    strcpy(objStudent.cName,"Gaurav");
    objStudent.fMarks = 70.90;
    objStudent.iAge = 23;

    write(iFD,&objStudent,sizeof(objStudent));

    return 0;
}
