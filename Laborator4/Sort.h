#pragma once
class Sort
{

private:

    int* v, n;
    bool cmp(int a, int b, bool ascendent);
    int partition(int st, int dr,bool ascendent);
    void quick(int st, int dr, bool ascendent);

public:

    Sort(int nr, int minn, int maxx);
    Sort(int n, int *v);
    Sort(int n, ...);
    Sort(char*c);
    Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

