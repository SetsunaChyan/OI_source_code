#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int limit)
{
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int l=rnd(1,limit);
        for(int j=0;j<l;j++)
            printf("%d",rand()&1);
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=25;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen(5,5);
        else if(i<=10) gen(10,10);
        else if(i<=15) gen(100,100);
        else if(i<=20) gen(1000,150);
        else if(i<=25) gen(10000,200);
        fclose(stdout);
    }
    return 0;
}
