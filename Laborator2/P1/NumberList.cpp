#include "NumberList.h"
#include <iostream>
#include <algorithm>

using namespace std;

void NumberList::Init()
{
    count = 0;
}

bool NumberList::Add(int x)
{
    if(count == 10)
        return false;

    numbers[count] = x;
    count++;
    return true;
}

void NumberList::Sort()
{
    sort(numbers, numbers+count);
}

void NumberList::Print()
{
    for(int i=0;i<this->count;i++)
        cout << numbers[i] << ' ';
    cout << '\n';
}
