#include "globale.h"
#include <cstring>

int CompareMath(student *A, student *B)
{
    float a = A->getGradeMath(), b = B->getGradeMath();
    if(a<b)
        return -1;
    if(a==b)
        return 0;
    if(a>b)
        return 1;
}

int CompareHist(student *A, student *B)
{
    float a = A->getGradeHist(), b = B->getGradeHist();
    if(a<b)
        return -1;
    if(a==b)
        return 0;
    if(a>b)
        return 1;
}

int CompareEngl(student *A, student *B)
{
    float a = A->getGradeEngl(), b = B->getGradeEngl();
    if(a<b)
        return -1;
    if(a==b)
        return 0;
    if(a>b)
        return 1;
}

int CompareAvg(student *A, student *B)
{
    float a = A->avg(), b = B->avg();
    if(a<b)
        return -1;
    if(a==b)
        return 0;
    if(a>b)
        return 1;
}

int CompareName(student *A, student *B)
{
    char *a=A->getNume(), *b=B->getNume();
    if(strcmp(a, b)<0)
        return -1;
    if(strcmp(a, b)==0)
        return 0;
    if(strcmp(a, b)>0)
        return 1;
}


