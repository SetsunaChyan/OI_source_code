#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int m,int k,int limit)
{
    int p=rnd(5,limit),q=rnd(5,limit),r=rnd(5,limit),mod=rnd(5,limit);
    printf("%d %d %d %d %d %d %d\n",n,m,k,p,q,r,mod);
    for(int i=0;i<k;i++)
        printf("%d ",rnd(0,limit));
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=25;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(15,i,10,5);
        else if(i<=15) gen(1000,100,200,50);
        else if(i<=20) gen(100000,100,20000,1000000000);
        else if(i<=25) gen(10000000,100,500000,1000000000);
        fclose(stdout);
    }
    return 0;
}
