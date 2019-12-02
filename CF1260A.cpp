#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll n,sum,a[10005];

void solve()
{
    scanf("%lld%lld",&n,&sum);
    ll t=sum%n;
    for(int i=0;i<n;i++) a[i]=sum/n;
    for(int i=0;i<t;i++) a[i]++;
    ll ans=0;
    for(int i=0;i<n;i++) ans+=a[i]*a[i];
    printf("%lld\n",ans);
}

int main()
{
    int _=1;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
