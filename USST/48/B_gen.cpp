#include <bits/stdc++.h>
using namespace std;

char des[100];

void gen()
{
    int k=1+rand()%10000;
    printf("%d\n",k);
    for(int i=1;i<=k;i++)
        printf("%d ",i);
}

int main()
{
    srand(time(NULL));
    for(int i=1;i<=50;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen();
        fclose(stdout);
    }
    return 0;
}