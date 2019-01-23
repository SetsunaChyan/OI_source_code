#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;

const int N=1e5+5;
int dis[N],head[N],tot=0,t,s,d,ans=0x3f3f3f3f,vis[N];
struct node
{
    int to,v,nxt;
}e[N<<1];
struct dij
{
    int num,v;
    bool operator < (const dij &b) const {return v>b.v;}
};
priority_queue<dij> q;

inline int min(int a,int b){return a<b?a:b;}

inline void addedge(int u,int v,int w)
{
    e[tot].nxt=head[u];
    e[tot].v=w;
    e[tot].to=v;
    head[u]=tot;
    tot++;
}

void dijs()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[0]=0;
    q.push((dij){0,0});
    while(!q.empty())
    {
        dij p=q.top();
        q.pop();
        if(vis[p.num]>1) continue;
        vis[p.num]++;
        for(int i=head[p.num];~i;i=e[i].nxt)
            if(dis[e[i].to]>dis[p.num]+e[i].v)
            {
                dis[e[i].to]=dis[p.num]+e[i].v;
                q.push((dij){e[i].to,dis[e[i].to]});
            }
    }
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&t,&s,&d);
    while(t--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    while(s--)
    {
        int x;
        scanf("%d",&x);
        addedge(0,x,0);
        addedge(x,0,0);
    }
    dijs();
    while(d--)
    {
        int x;
        scanf("%d",&x);
        ans=min(ans,dis[x]);
    }
    printf("%d",ans);
    return 0;
}