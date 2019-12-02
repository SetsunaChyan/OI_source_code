#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d,h,w;

void solve()
{
    scanf("%lld%lld%lld",&h,&w,&d);
    h%=2*w-2;
    ll cur=1;
    if(h==0&&d==2) printf("Yes\n");
    else if(h<=w&&h==d) printf("Yes\n");
    else if(h>w)
    {
        h-=w;
        if(h==w-d) printf("Yes\n"); else printf("No\n");
    }
    else printf("No\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

