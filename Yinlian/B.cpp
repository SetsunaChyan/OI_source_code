#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,vis[100005],st=0,flag=1;
ll val[100005],tmp[100005],sum=0,p=1;
vector<int> e[100005],v[100005];

void dfs1(int now,int u,int &start)
{
    vis[now]=1;
    for(int i=0;i<e[now].size();i++)
    {
        if(e[now][i]==u) continue;
        if(e[now][i]!=u&&vis[e[now][i]])
            start=e[now][i];
        else
            dfs1(e[now][i],now,start);
        if(start&&flag)
        {
            sum+=p*v[now][i];
            p*=-1;
            if(start==now) flag=0;
            return;
        }
    }
}

void dfs2(int now,int u)
{
    vis[now]=1;
    for(int i=0;i<e[now].size();i++)
    {
        if(e[now][i]==u||e[now][i]==st) continue;
        val[e[now][i]]=v[now][i]-val[now];
        dfs2(e[now][i],now);
    }
}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        e[x].push_back(y),v[x].push_back(z);
        e[y].push_back(x),v[y].push_back(z);
    }
    dfs1(1,1,st);
    val[st]=sum/2;
    memset(vis,0,sizeof(vis));
    dfs2(st,st);
    for(int i=1;i<=n;i++)
        printf("%lld\n",val[i]);
    return 0;
}

