#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n,m;
ll ans,tmp;

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        n-=1;m+=n-1;ans=tmp=1;
        for(int i=1;i<=m;i++)
            ans=ans*i%mod;
        for(int i=1;i<=n;i++)
            tmp=tmp*i%mod;
        ans=ans*fp(tmp,mod-2)%mod;
        tmp=1;
        for(int i=1;i<=m-n;i++)
            tmp=tmp*i%mod;
        ans=ans*fp(tmp,mod-2)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
