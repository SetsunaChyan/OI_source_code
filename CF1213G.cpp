#include <bits/stdc++.h>
using namespace std;

int siz[200005],msz[200005],root,sum,vis[200005];
vector<int> e[200005],val[200005];

void GetRoot(int x,int fa)
{
    siz[x]=1,msz[x]=0;
    for(int i=0;i<e[x].size();i++)
    {
        int y=e[x][i];
        if(y==fa||vis[y]) continue;
        GetRoot(y,x);
        siz[x]+=siz[y];
        msz[x]=max(msz[x],siz[y]);
    }
    msz[x]=max(msz[x],sum-siz[x]);
    if(msz[x]<msz[root]) root=x;
}

void GR_Init(int x,int fa)
{
    sum=siz[x];
    root=0;
    GetRoot(x,fa);
}

void Point_Divide(int x)
{
    vis[x]=1;
    Calc(x,0,1);
    for(int i=0;i<e[i].size();i++)
    {
        int y=e[x][i];
        if(vis[y]) continue;
        GR_Init(y,x);
        Point_Divide(root);
    }
}

void main()
{


}
