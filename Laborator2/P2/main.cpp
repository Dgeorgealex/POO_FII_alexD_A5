#include <iostream>
#include "student.h"
#include "globale.h"

using namespace std;

void citire(student &S, char o)
{
    float aux;
    char c[20];
    cout << o << '\n';
    cout << "nume: ";
    cin.getline(c, 20);
    S.setNume(c);

    cout << "mate: ";
    cin >> aux;
    S.setGradeMath(aux);

    cout << "istorie: ";
    cin >> aux;
    S.setGradeHist(aux);

    cout << "engleza: ";
    cin >> aux;
    S.setGradeEngl(aux);
    cin.get();
}
void afisare(student S)
{
    cout << "nume: " << S.getNume() << '\n';
    cout << "mate: " << S.getGradeMath() << '\n';
    cout << "istorie: " << S.getGradeHist() << '\n';
    cout << "engelza: " << S.getGradeEngl() << '\n';
    cout << "medie: " << S.avg() << '\n';
}

void comparari(student S1, student S2)
{
    cout << "nume: " << CompareName(&S1, &S2) << '\n';
    cout << "mate: " << CompareMath(&S1, &S2) << '\n';
    cout << "istorie: " << CompareHist(&S1, &S2) << '\n';
    cout << "engleza: " << CompareEngl(&S1, &S2) << '\n';
    cout << "medie: " << CompareAvg(&S1, &S2) << '\n';
}
int main()
{
    student S1, S2;
    citire(S1, '1');
    citire (S2, '2');

    cout << '\n';

    cout << "Afisare primul:\n";
    afisare(S1);

    cout << '\n';

    cout << "Afisare comparari:\n";
    comparari(S1, S2);
    return 0;
}
