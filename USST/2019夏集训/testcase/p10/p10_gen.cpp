#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen8()
{
    int n=1000,m=1000,k=100000;
    printf("%d %d %d\n",n,m,k);
    for(int i=0;i<n;i++)
        printf("%d %d\n",1+2*i,0);
    for(int i=0;i<m;i++)
        printf("%d %d %d\n",2*(i+1),0,0);
    for(int i=1;i<=100;i++)
        for(int j=1;j<=1000;j++)
            printf("%d %d\n",i,j);
}

void gen9()
{
    int n=1000,m=1000,k=100000;
    printf("%d %d %d\n",n,m,k);
    for(int i=0;i<n;i++)
        printf("%d %d\n",1+2*i,0);
    for(int i=0;i<m;i++)
        printf("%d %d %d\n",2*(i+1),0,0);
    for(int i=1;i<=k;i++)
        printf("%d %d\n",1,1000);
}

int main()
{
    srand(time(NULL));
    for(int i=8;i<=9;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i==8) gen8();
        if(i==9) gen9();
        fclose(stdout);
    }
    return 0;
}
