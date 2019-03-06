#include <cstdio>
#include <memory.h>

int n,t,dp[10005],head[10005],tot=0;
struct node
{
    int next,r;
}e[10005];

inline int max(int a,int b){return a>b?a:b;}

void add(int x,int y)
{
    e[tot].next=head[x];
    e[tot].r=y;
    head[x]=tot;
    tot++;
}

int main()
{
    memset(dp,0xc0,sizeof(dp));
    memset(head,-1,sizeof(head));
    scanf("%d%d",&t,&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    dp[t+1]=0;
    for(int i=t;i>=1;i--)
    {
        if(head[i]==-1)
            dp[i]=dp[i+1]+1;
        else
            for(int j=head[i];~j;j=e[j].next)
                dp[i]=max(dp[i+e[j].r],dp[i]);
    }
    printf("%d",dp[1]);
    return 0;
}