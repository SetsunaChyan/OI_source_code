#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int limit)
{
    printf("%d\n",n);
    for(int i=0;i<n;i++)
        printf("%d ",rnd(0,limit));
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen(5,10);
        else if(i<=10) gen(10,32);
        else if(i<=15) gen(100,10000);
        else if(i<=20) gen(100000,(1ll<<31)-1);
        fclose(stdout);
    }
    return 0;
}
