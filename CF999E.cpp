#include <bits/stdc++.h>
using namespace std;

int n,m,ce,deg[5005],ans,dfn[5005],low[5005],num,ins[5005],cnt,c[5005];
vector<int> e[5005];
stack<int> s;

void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    s.push(x),ins[x]=1;
    for(auto to:e[x])
        if(!dfn[to])
        {
            tarjan(to);
            low[x]=min(low[x],low[to]);
        }
        else if(ins[to])
            low[x]=min(low[x],dfn[to]);
    if(dfn[x]==low[x])
    {
        cnt++;int y;
        do
        {
            y=s.top();s.pop();ins[y]=0;
            c[y]=cnt;
        }while(x!=y);
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&ce);
    for(int i=0,u,v;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++)
        for(auto to:e[i])
        {
            if(c[i]==c[to]) continue;
            deg[c[to]]++;
        }
    for(int i=1;i<=cnt;i++)
        if(i!=c[ce]&&!deg[i]) ans++;
    printf("%d",ans);
    return 0;
}
