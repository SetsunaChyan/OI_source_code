#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int m,int limit)
{
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        int k=rnd(0,limit);
        if(rand()&1) k*=-1;
        printf("%d ",k);
    }
    printf("\n");
    for(int i=0;i<m;i++)
    {
        int x=rnd(1,n),y=rnd(1,n);
        if(x>y) swap(x,y);
        printf("%d %d\n",x,y);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(10,10,50);
        else if(i<=15) gen(10000,10000,10000);
        else if(i<=20) gen(500000,500000,10000000);
        fclose(stdout);
    }
    return 0;
}
