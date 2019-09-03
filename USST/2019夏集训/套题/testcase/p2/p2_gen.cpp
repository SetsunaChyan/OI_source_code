#include <bits/stdc++.h>
using namespace std;

char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen1()
{
    printf("%d\n",10);
    for(int T=0;T<10;T++)
    {
        int k=rnd(2,100);
        int m=rnd(k,100);
        printf("%d %d\n",k,m);
    }
}

void gen2()
{
    printf("%d\n",10);
    for(int T=0;T<10;T++)
    {
        int k=rnd(2,1000);
        int m=rnd(k,1000);
        printf("%d %d\n",k,m);
    }
}

void gen3()
{
    printf("%d\n",10);
    for(int T=0;T<10;T++)
    {
        int k=rnd(2,100000);
        int m=rnd(k,100000);
        printf("%d %d\n",k,m);
    }
}

void gen4()
{
    printf("%d\n",10);
    for(int T=0;T<10;T++)
    {
        int k=rnd(2,100000);
        int m=rnd(k,100000);
        printf("%d %d\n",m,k);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=17;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen1();
        else if(i<=10) gen2();
        else if(i<=15) gen3();
        else if(i<=17) gen4();
        fclose(stdout);
    }
    return 0;
}
