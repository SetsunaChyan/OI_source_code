#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

void gen1()
{
    n=1+rand()%200000;
    m=400000/n;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",rand()&1);
        printf("\n");
    }
}

void gen2()
{
    n=1+rand()%200000;
    m=400000/n;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        int k=rand()&1;
        for(int j=0;j<m;j++)
            printf("%d ",k);
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=31;i<=50;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=30) gen1(); else gen2();
        fclose(stdout);
    }
    return 0;
}