#include <bits/stdc++.h>
using namespace std;

char des[100];

void gen()
{
    int n=10000,m=1000;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<100;j++)
            printf("%c",'A'+rand()%26);
        printf("\n");
    }
    for(int i=0;i<m;i++)
    {
        int x=1+rand()%100,y=1+rand()%100;
        if(x>y) swap(x,y);
        printf("%d %d\n",x,y);
    }
}

void gen1()
{
    int n=10000,m=1000;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<100;j++)
            printf("%c",'A'+(rand()&1));
        printf("\n");
    }
    for(int i=0;i<m;i++)
    {
        int x=1+rand()%100,y=1+rand()%100;
        if(x>y) swap(x,y);
        printf("%d %d\n",x,y);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen();
        fclose(stdout);
    }
    for(int i=21;i<=22;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen1();
        fclose(stdout);
    }
    return 0;
}