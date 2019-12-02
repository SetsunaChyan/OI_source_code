#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,n,s;

void solve()
{
    scanf("%lld%lld%lld%lld",&a,&b,&n,&s);
    if(s%n<=b) b-=s%n,s-=s%n; else
    {
        printf("NO\n");
        return;
    }
    a+=b/n;
    if(s/n<=a)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();

    return 0;
}
