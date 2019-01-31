#include <cstdio>

typedef long long ll;
int n;
ll v[50],w[50],suf[50],ans=0,m;

inline ll max(ll a,ll b){return a>b?a:b;}

void dfs(int dep,ll V,ll sum)
{
    if(dep==n)
    {
        ans=max(sum,ans);
        return;
    }
    if(sum+suf[dep]<=ans) return;
    if(V+v[dep]<=m)
        dfs(dep+1,V+v[dep],sum+w[dep]);
    dfs(dep+1,V,sum);
}

int main()
{
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&v[i],&w[i]);
    suf[n]=0;
    for(int i=n-1;i>=0;i--)
        suf[i]=suf[i+1]+w[i];
    dfs(0,0,0);
    printf("%lld",ans);
    return 0;
}