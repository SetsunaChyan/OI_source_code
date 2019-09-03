#include <bits/stdc++.h>
using namespace std;

const char T[4]={'A','C','T','G'};
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void genE(int n,int m)
{
    printf("%d %d\n",m,n);
    for(int i=0;i<m;i++)
    {
        int len=rand()%3+1;
        for(int j=0;j<len;j++) putchar(T[rand()%4]);
        puts("");
    }
}

void gen(int n,int m)
{
    printf("%d %d\n",m,n);
    for(int i=0;i<m;i++)
    {
        int len=rand()%10+1;
        for(int j=0;j<len;j++) putchar(T[rand()%4]);
        puts("");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=1;i<=30;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) genE(5,i);
        else if(i<=10) genE(10,i-5);
        else if(i<=15) gen(100,5);
        else if(i<=20) gen(100,10);
        else if(i<=25) gen(100000000,10);
        else if(i<=30) gen(2000000000,10);
        fclose(stdout);
    }
    return 0;
}
