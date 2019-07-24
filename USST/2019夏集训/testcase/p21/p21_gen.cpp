#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int m,int limit)
{
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",(rand()%limit)>0);
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=30;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen(5,5,2);
        else if(i<=10) gen(10,10,2);
        else if(i<=15) gen(100,100,2);
        else if(i<=20) gen(1000,1000,2);
        else gen(1000,1000,i-20);
        fclose(stdout);
    }
    return 0;
}
