#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
    ll a,b;
    scanf("%lld%lld",&a,&b);
    if((a+b)%3==0&&(max(b,a)<=2*min(a,b))) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int _=1;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
