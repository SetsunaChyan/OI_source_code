#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5e5+5;
int a[MAXN],n,k,N;
ll ans;

void solve()
{
    ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(a[i]+a[j]-(i-j)>=k) ans++;
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
