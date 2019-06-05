#include <bits/stdc++.h>
using namespace std;

char des[100];

int main()
{
    srand(time(NULL));
    for(int i=1;i<=50;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        printf("%d",2+rand()%9999);
        fclose(stdout);
    }
    return 0;
}