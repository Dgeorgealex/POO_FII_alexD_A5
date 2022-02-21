#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define ll long long

using namespace std;

int main()
{
	FILE* fp = fopen("in.txt", "r");
	if (!fp)
        return 0;

	char c[20];
    ll sum=0;

    while (fgets(c, 20, fp))
    {
        c[strlen(c)-1]='\0';
        int n=strlen(c);
        ll nr=0;
        for(int i=0;i<n;i++)
            nr=nr*10+(c[i]-'0');

        sum=sum+nr;
    }

    printf("%lld", sum);
	return 0;
}
