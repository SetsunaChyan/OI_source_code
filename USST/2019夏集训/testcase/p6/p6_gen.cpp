#include <bits/stdc++.h>
using namespace std;

int n,m,fa[100005];
char des[100];

int _find(int x){return x==fa[x]?x:fa[x]=_find(fa[x]);}

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int v)
{
    printf("%d\n",n);
    for(int i=1;i<=n;i++) fa[i]=i;
    int cnt=0;
    while(cnt<n-1)
    {
        int x=rnd(1,n),y=rnd(1,n);
        int x1=_find(x),y1=_find(y);
        if(x1!=y1)
        {
            fa[x1]=y1;
            cnt++;
            printf("%d %d %d\n",x,y,rnd(1,v));
        }
    }
}

int main()
{
    srand(time(NULL));
    for(int i=1;i<=25;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(i+3,10);
        else if(i<=15) gen(i*100,100);
        else if(i<=20) gen(i*1000,100);
        else if(i<=25) gen(100000,100);
        fclose(stdout);
    }
    return 0;
}
