#include <bits/stdc++.h>
using namespace std;

int n,x,s,y;

void solve()
{
    x=s=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&y);
        s+=y;
        x=__gcd(x,y);
    }
    printf("%d %d\n",x,s/x);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

