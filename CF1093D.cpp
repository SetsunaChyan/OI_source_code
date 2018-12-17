#include <cstdio>

const int mod=998244353;
int n,m,tot,head[300005],vis[300005],de[300005],tmp;
long long ans;
struct node
{
    int to,next;
}e[600005];

inline void addedge(int x,int y)
{
    e[tot].next=head[x];
    e[tot].to=y;
    head[x]=tot;
    tot++;
}

void dfs(int x,int dep,int flag)
{
    vis[x]=flag;
    de[x]=dep;
    if(flag==1&&!(dep&1)||flag==2&&(dep&1)) tmp=tmp*2%mod;
    for(int i=head[x];~i;i=e[i].next)
        if(vis[e[i].to]==flag)
            {if((dep+de[e[i].to])%2==0) tmp=0;}
        else
            dfs(e[i].to,dep+1,flag);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        tot=0;
        ans=1;
        for(int i=0;i<n;i++)
        {
            head[i]=-1;
            vis[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(x-1,y-1);
            addedge(y-1,x-1);
        }
        for(int i=0;i<n;i++)
        {
            int t=0;
            if(vis[i]==0) 
            {
                tmp=1;dfs(i,0,1);t=tmp;
                tmp=1;dfs(i,0,2);t=(t+tmp)%mod;
                ans=(ans*(long long)t)%mod;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}