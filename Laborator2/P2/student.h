#pragma once
class student
{
private:
    float engl, hist, math;
    char nume[20];
public:
    student();

    void setNume(char *nume);
    char* getNume();

    void setGradeEngl(float x);
    float getGradeEngl();

    void setGradeHist(float x);
    float getGradeHist();

    void setGradeMath(float x);
    float getGradeMath();

    float avg();
};
