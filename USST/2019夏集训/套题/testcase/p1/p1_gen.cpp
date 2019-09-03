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
    printf("%d\n",5);
    for(int T=0;T<5;T++)
    {
        printf("%d %d\n",5,rnd(1,5));
        for(int j=0;j<5;j++) printf("%d ",rnd(1,5));
        printf("\n");
    }
}

void gen2()
{
    printf("%d\n",1000);
    for(int T=0;T<1000;T++)
    {
        printf("%d %d\n",10,rnd(1,10));
        for(int j=0;j<10;j++) printf("%d ",rnd(1,10));
        printf("\n");
    }
}

void gen3()
{
    printf("%d\n",1000);
    for(int T=0;T<1000;T++)
    {
        printf("%d %d\n",1000,rnd(1,1000));
        for(int j=0;j<1000;j++) printf("%d ",rnd(1,1000));
        printf("\n");
    }
}

void genFULL1()
{
    printf("%d\n",5);
    for(int T=0;T<5;T++)
    {
        printf("%d %d\n",200000,1);
        for(int j=0;j<200000;j++) printf("%d ",200000);
        printf("\n");
    }
}

void genFULL2()
{
    printf("%d\n",5);
    for(int T=0;T<5;T++)
    {
        printf("%d %d\n",200000,200000);
        for(int j=0;j<200000;j++) printf("%d ",200000);
        printf("\n");
    }
}

void gen4()
{
    printf("%d\n",5);
    for(int T=0;T<5;T++)
    {
        printf("%d %d\n",200000,rnd(1,200000));
        for(int j=0;j<200000;j++) printf("%d ",rnd(1,200000));
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=15;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=4) gen1();
        else if(i<=6) gen2();
        else if(i<=10) gen3();
        else if(i<=11) genFULL1();
        else if(i<=12) genFULL2();
        else if(i<=15) gen4();
        fclose(stdout);
    }
    return 0;
}
