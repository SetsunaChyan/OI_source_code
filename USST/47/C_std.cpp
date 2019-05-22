#include <bits/stdc++.h>
using namespace std;

int n,head[10005],r,tot;
struct edge
{
    int to,nxt;
}e[10005<<1];

void add_edge(int x,int y)
{
    e[tot].nxt=head[x];
    e[tot].to=y;
    head[x]=tot;
    tot++;
}

bool dfs(int now,int fa)
{
    bool ret=false;
    for(int i=head[now];~i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        ret=ret||!dfs(e[i].to,now);
    }
    return ret;
}

void solve()
{
    memset(head,-1,sizeof(head));
    tot=0;
    scanf("%d%d",&n,&r);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    if(dfs(r,-1)) printf("Haruhi go first.\n"); else printf("Haruhi go secondary.\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
        solve();
    return 0;
}