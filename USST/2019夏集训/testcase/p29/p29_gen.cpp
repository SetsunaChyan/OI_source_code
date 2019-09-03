#include <bits/stdc++.h>
using namespace std;

const char T[4]={'A','C','T','G'};
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen8()
{
    printf("200000\n");
    for(int i=0;i<200000;i++) printf("%d ",1);
}

void gen9()
{
    printf("200000\n2 ");
    for(int i=1;i<200000;i++) printf("%d ",1);
}

void gen10()
{
    printf("200000\n2 ");
    for(int i=1;i<200000-1;i++) printf("%d ",1);
    printf("2 ");
}

void gen11()
{
    printf("200000\n");
    for(int i=0;i<200000;i++) printf("%d ",rnd(1,1000000000));
}

void gen12_13()
{
    printf("200000\n");
    for(int i=0;i<200000;i+=2)
    {
        int k=rand()&1;
        printf("%d %d ",1+k,1+k);
    }
}

void gen14_15()
{
    printf("200000\n");
    for(int i=0;i<200000;i+=2)
    {
        int k=rand()&1;
        k*=1000000;
        printf("%d %d ",500000+k,500000+k);
    }
}

void gen16()
{
    printf("200000\n");
    for(int i=0;i<200000;i+=2)
        printf("%d %d ",600000-2*i,600000-2*i);
}

void gen17()
{
    printf("200000\n");
    for(int i=0;i<200000;i+=2)
        printf("%d %d ",600000+2*i,600000+2*i);
}

int main()
{
    srand(time(NULL));
    for(int i=8;i<=17;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=8) gen8();
        else if(i<=9) gen9();
        else if(i<=10) gen10();
        else if(i<=11) gen11();
        else if(i<=13) gen12_13();
        else if(i<=15) gen14_15();
        else if(i<=16) gen16();
        else if(i<=17) gen17();
        fclose(stdout);
    }
    return 0;
}
