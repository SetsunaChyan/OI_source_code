#include <cstdio>
#include <memory.h>

struct node
{
    int to,next;
}e[105];
int n,ans=0x3f3f3f3f,tot=0,head[105],val[105],d[105];

inline int min(int a,int b){return a<b?a:b;}
inline void addedge(int x,int y)
{
    e[tot].next=head[x];
    head[x]=tot;
    e[tot].to=y;
    tot++;
}

void dfs(int now,int fa,int dep)
{
    d[now]=dep;
    for(int i=head[now];~i;i=e[i].next)
        if(e[i].to!=fa)
            dfs(e[i].to,now,dep+1);
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d%d",&val[i],&x,&y);
        if(x)
        {
            addedge(i,x-1);
            addedge(x-1,i);
        }
        if(y)
        {
            addedge(i,y-1);
            addedge(y-1,i);
        }
    }
    for(int i=0;i<n;i++)
    {
        dfs(i,i,0);
        int temp=0;
        for(int j=0;j<n;j++)
            temp+=d[j]*val[j];
        ans=min(temp,ans);
    }
    printf("%d",ans);
    return 0;
}