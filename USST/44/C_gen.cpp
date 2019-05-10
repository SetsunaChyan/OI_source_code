#include <bits/stdc++.h>
using namespace std;

char des[100];
int n,m,op,x,y;

void gen1()
{
    //连成一条链
    n=10+rand()%30000,m=50000;
    printf("%d %d\n",n,m);
    for(int i=1;i<n;i++)
    {
        op=1,x=i,y=i+1;
        m--;
        printf("%d %d %d\n",op,x,y);
    }
    while(m--)
    {
        op=2+rand()%2;
        x=1+rand()%n;
        printf("%d %d\n",op,x);
    }
}

void gen2()
{
    //随机
    n=50000,m=50000;
    printf("%d %d\n",n,m);
    while(m--)
    {
        op=1+rand()%3,x=1+rand()%n,y=1+rand()%n;
        if(op==1) printf("%d %d %d\n",op,x,y); else printf("%d %d\n",op,x);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=4;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        //printf("%s\n",des);
        freopen(des,"w",stdout);
        if(i<=10) gen1();
        else gen2();
        fclose(stdout);
    }
    return 0;
}