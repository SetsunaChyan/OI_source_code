#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int q,int limit)
{
    printf("%d %d\n",n,q);
    for(int i=0;i<q;i++)
    {
        int op=rand()%4+1,x=rnd(1,n),y=rnd(1,n);
        if(x>y) swap(x,y);
        if(op==4)
            printf("%d %d %d %d\n",op,x,y,1+rand()%3);
        else
            printf("%d %d %d %d\n",op,x,y,rnd(1,limit));
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(10,10,10);
        else if(i<=15) gen(100,100,100);
        else if(i<=20) gen(100000,100000,100000);
        fclose(stdout);
    }
    return 0;
}
