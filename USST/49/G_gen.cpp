#include <bits/stdc++.h>
using namespace std;

char des[100];

void gen()
{
    int l=1+rand()%5000,r=1+rand()%5000;
    if(l>r) swap(l,r);
    printf("%d %d",l,r);
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=50;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen();
        fclose(stdout);
    }
    return 0;
}