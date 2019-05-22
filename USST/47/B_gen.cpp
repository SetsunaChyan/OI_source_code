#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen()
{
    printf("%lld %lld %lld\n",rnd(1,100),rnd(1,2000000000),rnd(1,2000000000));
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