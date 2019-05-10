#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
set<ll> vis;
char des[100];

void gen1()
{
    n=20;m=20;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        ll x=1+rand()%100;
        while(vis.find(x)!=vis.end()) x=1+rand()%100;
        printf("%lld ",x);
        vis.insert(x);
    }
    printf("\n");
    for(int i=0;i<m;i++)
    {
        ll x=1+rand()%100;
        printf("%lld ",x);
    }
    printf("\n");
    for(int i=0;i<m;i++)
    {
        int x=1+rand()%n;
        printf("%d ",x);
    }
}

void gen2()
{
    n=1000;m=1000;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        ll x=1+((long long)rand())*rand()*rand();
        while(vis.find(x)!=vis.end()) x=1+((long long)rand())*rand()*rand();
        printf("%lld ",x);
        vis.insert(x);
    }
    printf("\n");
    for(int i=0;i<m;i++)
    {
        ll x=1+((long long)rand())*rand()*rand();
        printf("%lld ",x);
    }
    printf("\n");
    for(int i=0;i<m;i++)
    {
        int x=1+rand()%n;
        printf("%d ",x);
    }
}

void gen3()
{
    n=10000;m=10000;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        ll x=1+((long long)rand())*rand()*rand();
        while(vis.find(x)!=vis.end()) x=1+((long long)rand())*rand()*rand();
        printf("%lld ",x);
        vis.insert(x);
    }
    printf("\n");
    for(int i=0;i<m;i++)
    {
        ll x=1+((long long)rand())*rand()*rand();
        printf("%lld ",x);
    }
    printf("\n");
    for(int i=0;i<m;i++)
    {
        int x=1+rand()%n;
        printf("%d ",x);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=30;i++)
    {
        vis.clear();
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen1();
        else if(i<=10) gen2();
        else gen3();
        fclose(stdout);
    }
    return 0;
}