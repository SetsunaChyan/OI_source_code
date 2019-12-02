#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b;

void solve()
{
    scanf("%lld%lld",&a,&b);
    if(b<=a)
    {
        printf("YES\n");
        return;
    }
    if(a==1)
    {
        printf("NO\n");
        return;
    }
    if(a<=3&&b>3)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
