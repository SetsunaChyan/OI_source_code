#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll a[3];

void solve()
{
    scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
    sort(a,a+3);
    ll t=min(a[0],a[2]-a[1]);
    a[1]+=t;
    a[0]-=t;
    //printf("! %lld %lld %lld\n",a[0],a[1],a[2]);
    printf("%lld\n",min(a[1],a[2])+a[0]/2);
}

int main()
{
    int _=1;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
