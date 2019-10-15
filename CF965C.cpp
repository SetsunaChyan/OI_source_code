#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,m,d,ans;

int main()
{
    scanf("%lld%lld%lld%lld",&n,&k,&m,&d);
    for(int i=1;i<=d;i++)
    {
        if(i*k-k+1>n) break;
        ll x=min(n/(i*k-k+1),m);
        ans=max(ans,i*x);
    }
    printf("%lld",ans);
    return 0;
}
