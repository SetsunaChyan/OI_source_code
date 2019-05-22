#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen1()
{
    int T=100;
    while(T--)
    {
        int a=rnd(1,100),b=rnd(1,100),k=rnd(1,100);
        n=rnd(1,k);
        printf("%d %d %d %d\n",a,b,k,n);
    }
}

void gen2()
{
    int T=100000;
    while(T--)
    {
        int a=rnd(1,1000000),b=rnd(1,1000000),k=rnd(1,1000);
        n=rnd(1,k);
        printf("%d %d %d %d\n",a,b,k,n);
    }
}

void gen3()
{
    int T=400000;
    while(T--)
    {
        int a=rnd(1,1000000),b=rnd(1,1000000),k=rnd(1,1000);
        n=rnd(1,k);
        printf("%d %d %d %d\n",a,b,k,n);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=4;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i==2) gen1(); 
        else if(i==3) gen2();
        else gen3();
        fclose(stdout);
    }
    return 0;
}