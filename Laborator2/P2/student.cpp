#include "student.h"
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

student::student()
{
    this->math=0;
    this->hist=0;
    this->engl=0;
    memset(this->nume, 0, sizeof(this->nume));
}
void student::setGradeMath(float x)
{
    this->math = x;
}
void student::setGradeEngl(float x)
{
    this->engl = x;
}
void student::setGradeHist(float x)
{
    this->hist = x;
}
float student::getGradeMath()
{
    return this->math;
}
float student::getGradeEngl()
{
    return this->engl;
}
float student::getGradeHist()
{
    return this->hist;
}
float student::avg()
{
    float m=this->getGradeMath(), e=this->getGradeEngl(), h=this->getGradeHist();
    return (m+h+e)/3;
}
void student::setNume(char *nume)
{
    strcpy(this->nume, nume);
}
char *student::getNume()
{
    return this->nume;
}

