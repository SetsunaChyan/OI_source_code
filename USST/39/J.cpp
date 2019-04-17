#include <cstdio>
#include <memory.h>

int n,k=0,tot=0,head[300005],dp[300005],f[300005];
struct edge
{
    int to,nxt;
}e[300005];

inline void add(int a,int b)
{
    e[tot].nxt=head[a];
    e[tot].to=b;
    head[a]=tot++;
}

inline int min(int a,int b){return a<b?a:b;}

void dfs(int now)
{
    if(head[now]==-1)
    {
        dp[now]=1;
        return;
    }
    if(!f[now]) dp[now]=0; else dp[now]=k;
    for(int i=head[now];~i;i=e[i].nxt)
    {
        dfs(e[i].to);
        if(f[now]) dp[now]=min(dp[now],dp[e[i].to]); else dp[now]+=dp[e[i].to];
    }
}

int main()
{
    memset(head,-1,sizeof head);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&f[i+1]);
    for(int i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        add(x,i+1);
    }
    for(int i=1;i<=n;i++)
        if(head[i]==-1) k++;
    dfs(1);
    printf("%d",k-dp[1]+1);
    return 0;
}