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
    printf("%d\n",1000);
    for(int T=0;T<1000;T++)
    {
        printf("1");
        for(int i=2;i<=10-1;i++) printf("%d",rand()&1);
        printf("1\n");
    }
}

void gen2()
{
    printf("%d\n",1000);
    for(int T=0;T<1000;T++)
    {
        printf("1");
        for(int i=2;i<=100-1;i++) printf("%d",rand()&1);
        printf("1\n");
    }
}

void gen3()
{
    printf("%d\n",1000);
    for(int T=0;T<1000;T++)
    {
        printf("1");
        for(int i=2;i<=1000-1;i++) printf("%d",rand()&1);
        printf("1\n");
    }
}

void gen4()
{
    printf("%d\n",100);
    for(int T=0;T<100;T++)
    {
        printf("1");
        for(int i=2;i<=10000-1;i++) printf("%d",rand()&1);
        printf("1\n");
    }
}

void gen8()
{
    printf("%d\n",10);
    for(int T=0;T<10;T++)
    {
        printf("1");
        for(int i=2;i<=100000-1;i++) printf("%d",rand()&1);
        printf("1\n");
    }
}

void gen5()
{
    printf("%d\n",10);
    for(int T=0;T<10;T++)
    {
        printf("1");
        for(int i=2;i<=100000-1;i++) printf("0");
        printf("1\n");
    }
}

void gen6()
{
    printf("%d\n",10);
    for(int T=0;T<10;T++)
    {
        printf("1");
        for(int i=2;i<=100000-1;i++) printf("1");
        printf("1\n");
    }
}

void gen7()
{
    printf("%d\n",10);
    for(int T=0;T<10;T++)
    {
        printf("1");
        for(int i=2;i<=100000-1;i++) printf("%d",rand()<=10);
        printf("1\n");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen1();
        else if(i<=8) gen2();
        else if(i<=11) gen3();
        else if(i<=14) gen4();
        else if(i<=15) gen5();
        else if(i<=16) gen6();
        else if(i<=17) gen7();
        else if(i<=20) gen8();
        fclose(stdout);
    }
    return 0;
}
