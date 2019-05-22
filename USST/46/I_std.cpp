#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,k,miu[1000005];
int vis[1000005];

void sel(int n)
{
    for(int i=1;i<=n;i++)
        vis[i]=0,miu[i]=1;
    for(int i=2;i<=n;i++)
    {
        if(vis[i]) continue;
        miu[i]=-1;
        for(int j=2*i;j<=n;j+=i)
        {
            vis[j]=1;
            if((j/i)%i==0) miu[j]=0; else miu[j]*=-1;
        }
    }
}

void solve()
{
    scanf("%lld%lld%lld",&a,&b,&k);
    a/=k,b/=k;
    ll ans=0,p=min(a,b);
    for(int i=1;i<=p;i++)
        ans+=miu[i]*(a/i)*(b/i);
    printf("%lld\n",ans);
}

int main()
{
    int _;
    sel(1000000);
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}   