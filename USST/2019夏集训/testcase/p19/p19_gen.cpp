#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int limit)
{
    printf("%d %d %d\n",n,rnd(1,100),rnd(1,100));
    for(int i=0;i<n;i++)
        printf("%d ",rnd(1,limit));
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(10,10);
        else if(i<=15) gen(100,100);
        else if(i<=20) gen(100000,1000000000);
        fclose(stdout);
    }
    return 0;
}
