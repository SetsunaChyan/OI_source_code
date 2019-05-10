#include <bits/stdc++.h>
using namespace std;

int n,m,s,x,y;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen()
{
    n=100;
    m=min(n,1+rand()%50);
    s=rnd(250,500);
    printf("%d %d %d\n",n,m,s);
    for(int i=0;i<n;i++)
    {
        x=rnd(1,20);
        y=rnd(1,10000000);
        printf("%d %d\n",x,y);
    }
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