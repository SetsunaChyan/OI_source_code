#include <bits/stdc++.h>
using namespace std;

char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen()
{
    int n=100000,m=100000;
    int k=3,g=n/20/k;
    printf("%d %d\n",n,m);
    while(m--)
    {
        int op;
        if(rand()%20)
            op=2;
        else 
            op=1;
        if(op==1&&g) g--; else op=2; 
        printf("%d ",op);
        int l=rnd(1,n),r=rnd(1,n);
        if(l>r) swap(l,r);
        printf("%d %d ",l,r);
        if(op==1)
        {
            printf("%d ",k);
            for(int i=0;i<k;i++)
                printf("%d ",1+rand()%60);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=1;i<=10;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen();
        fclose(stdout);
    }
    return 0;
}