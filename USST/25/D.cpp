#include <cstdio>
#include <memory.h>

typedef long long ll;
ll dis[1005][1005],t,s,d,ans=0x3f3f3f3f3f3f3f3fll,tt=1;

inline ll min(ll a,ll b){return a<b?a:b;}
inline ll max(ll a,ll b){return a>b?a:b;}

int main()
{
    memset(dis,0x3f,sizeof(dis));
    scanf("%lld%lld%lld",&t,&s,&d);
    for(int i=0;i<t;i++)
    {
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        dis[x][y]=dis[y][x]=min(dis[y][x],z);
        tt=max(tt,x);
        tt=max(tt,y);
    }
    for(int k=1;k<=tt;k++)
        for(int i=1;i<=tt;i++)
            for(int j=1;j<=tt;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=0;i<d;i++)
    {
        ll x;
        scanf("%lld",&x);
        ans=min(ans,dis[1][x]);
    }
    printf("%lld",ans);
    return 0;
}