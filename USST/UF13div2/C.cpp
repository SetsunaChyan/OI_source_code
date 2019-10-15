#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n;
ll ans,a[300005],p[300005];

int main()
{
    scanf("%d",&n);
    p[0]=1;
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i),p[i]=2*p[i-1]%mod;
    sort(a+1,a+1+n,greater<ll>());
    for(int i=1;i<=n;i++)
        ans+=(p[n-i]-1)%mod*a[i]%mod,ans-=(p[i-1]-1)%mod*a[i]%mod,ans=(ans+mod*mod)%mod;
    printf("%lld",ans);
    return 0;
}
