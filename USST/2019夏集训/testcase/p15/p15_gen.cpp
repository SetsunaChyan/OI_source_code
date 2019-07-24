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
        for(int j=0;j<n;j++)
            printf("%d ",rnd(0,limit));
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
        if(i<=10) gen(5,100);
        else if(i<=15) gen(10,1000);
        else if(i<=20) gen(100,10000);
        else if(i<=25) gen(1000,100000);
        fclose(stdout);
    }
    return 0;
}
