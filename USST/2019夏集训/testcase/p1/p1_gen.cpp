#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int l,int r)
{
    printf("%d\n",n);
    for(int i=0;i<n;i++)
        printf("%d ",rnd(l,r));
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=50;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(5,1,10);
        else if(i<=15) gen(10,1,10);
        else if(i<=20) gen(10,1,20);
        else if(i<=25) gen(10,1,1000000000);
        else if(i<=30) gen(100,1,1000000000);
        else if(i<=40) gen(50000,1,1000000000);
        else if(i<=45) gen(500000,1,100);
        else gen(500000,1,1000000000);
        fclose(stdout);
    }
    return 0;
}
