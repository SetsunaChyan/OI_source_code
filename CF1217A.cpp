#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a,b,c;

void solve()
{
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",max(0,b+c-a<0?c+1:c-(b+c-a)/2));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
