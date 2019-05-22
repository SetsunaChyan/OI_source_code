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
    int T=10;
    printf("%d\n",T);
    while(T--)
    {
        int a=rnd(1,1000000),b=rnd(1,1000000),k=rnd(1,1000000);
        printf("%d %d %d\n",a,b,k);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=3;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen();
        fclose(stdout);
    }
    return 0;
}