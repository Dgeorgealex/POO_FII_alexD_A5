#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
    NumberList l;
    l.Init();

    while(1)
    {
        char op;
        cin >> op;
        if(op=='e')
            break;
        if(op=='i')
        {
            int x;
            cin >> x;
            if(l.Add(x)==false)
            {
                cout << "prea multe\n";
                break;
            }
        }
        if(op=='s')
            l.Sort();

        if(op=='a')
            l.Print();
    }

    cout << "Program terminat";
    return 0;
}
