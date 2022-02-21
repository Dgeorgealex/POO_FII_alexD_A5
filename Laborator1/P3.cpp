#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

bool criteriu(char a[], char b[])
{
    if(strlen(a)==strlen(b))
        return (strcmp(a, b) > 0);
    else return strlen(a) < strlen(b);
}
char c[10000], *p, cuv[100][100];
int n;
int main()
{

    scanf("%[^\n]s", c);

    p=strtok(c, " ");
    while(p!=NULL)
    {
        n++;
        strcpy(cuv[n], p);
        p=strtok(NULL, " ");
    }

    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(criteriu(cuv[i], cuv[j]))
            {
                char aux[100];
                strcpy(aux, cuv[i]);
                strcpy(cuv[i], cuv[j]);
                strcpy(cuv[j], aux);
            }

    for(int i=1;i<=n;i++)
        printf("%s\n", cuv[i]);
    return 0;
}
