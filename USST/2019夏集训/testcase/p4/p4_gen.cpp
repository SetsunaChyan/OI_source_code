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
    printf("\n%d\n",n);
    for(int i=0;i<n;i++)
    {
        int x=rnd(1,n),y=rnd(1,n);
        if(x>y) swap(x,y);
        printf("%d %d\n",x,y);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=30;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen(10,0,10);
        else if(i<=10) gen(50,0,50);
        else if(i<=15) gen(100,0,500);
        else if(i<=20) gen(1000,0,50000);
        else if(i<=25) gen(10000,0,1000000);
        else if(i<=30) gen(500000,0,1000000);
        fclose(stdout);
    }
    return 0;
}
