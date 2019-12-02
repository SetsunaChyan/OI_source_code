#include <bits/stdc++.h>
using namespace std;

int n,vis[1005],x[1005],y[1005],r[1005];
vector<int> e;

bool check(int a,int b)
{
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])==(r[a]+r[b])*(r[a]+r[b]);
}

void dfs(int now,int dep)
{
    if(dep&1) vis[now]=1; else vis[now]=-1;
    for(int i=0;i<n;i++)
        if(!vis[i]&&check(now,i))
            dfs(i,dep+1);
}

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        vis[i]=0,scanf("%d%d%d",x+i,y+i,r+i);
    dfs(0,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            printf("not moving\n");
            continue;
        }
        int t=__gcd(r[0],r[i]);
        if(r[0]%r[i]==0) printf("%d ",r[0]/r[i]);
        else printf("%d/%d ",r[0]/t,r[i]/t);
        printf("%s\n",vis[i]==-1?"clockwise":"counterclockwise");
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
