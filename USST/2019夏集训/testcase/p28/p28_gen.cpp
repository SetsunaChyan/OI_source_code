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

void gen(int n)
{
    for(int i=0;i<n;i++) putchar('a'+rand()%2);
}

void gen2(int n)
{
    for(int i=0;i<n;i++) putchar('c'+rand()%24);
}

void gen3(int n)
{
    for(int i=0;i<n;i++) putchar('a'+rand()%26);
}

int main()
{
    srand(time(NULL));
    for(int i=4;i<=35;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen(5);
        else if(i<=10) gen(10);
        else if(i<=15) gen(100);
        else if(i<=20) gen(10000);
        else if(i<=25) gen(100000);
        else if(i<=30) gen2(100000);
        else if(i<=35) gen3(100000);
        fclose(stdout);
    }
    return 0;
}
