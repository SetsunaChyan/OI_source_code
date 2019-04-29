#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;
int n,tot=0,cnt[MAXN],head[MAXN],root;
struct edge
{
    int to,nxt;
}e[MAXN<<1];

void addedge(int x,int y)
{
    e[tot].nxt=head[x];
    e[tot].to=y;
    head[x]=tot++;
}

void dfs(int fa,int now)
{
    int res=0;
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=fa)
        {
            dfs(now,e[i].to);
            res+=cnt[e[i].to];
        }
    cnt[now]=res+1;
}

void dfs2(int fa,int now)
{
    for(int i=head[now];~i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        if(~cnt[e[i].to]&1) dfs2(now,e[i].to);
    }
    printf("%d ",now);
    for(int i=head[now];~i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        if(cnt[e[i].to]&1) dfs2(now,e[i].to);
    }
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    if(~n&1)
    {
        printf("NO");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        addedge(x,i+1);
        addedge(i+1,x);
    }
    dfs(0,e[head[0]].to);
    printf("YES\n");
    dfs2(0,e[head[0]].to);
    return 0;
}