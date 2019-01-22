// not solved
#include <cstdio>
#include <memory.h>

typedef long long ll;
int n;
ll l,x[200050],vis[200050],ans=0;

inline ll max(ll a,ll b){return a>b?a:b;}
inline ll abs(ll x){return x<0?-x:x;}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%lld%d",&l,&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    ll p=0;
    x[0]=0;
    for(int i=0;i<n;i++)
    {
        vis[p]=1;
        ll tmp,tp;
        for(int j=p;;j=j<n?j+1:1)
        {
            if(vis[j]) continue;
            ll k=x[j]-x[p];
            if(k<0) k+=l;
            tmp=k;
            tp=j;
            break;
        }
        for(int j=p;;j=j>1?j-1:n)
        {
            if(vis[j]) continue;
            ll k=x[p]-x[j];
            if(k<0) k+=l;
            if(tmp<k)
            {
                tmp=k;
                tp=j;
            }
            break;
        }
        ans+=tmp;
        p=tp;
    }
    printf("%lld",ans);
    return 0;
}