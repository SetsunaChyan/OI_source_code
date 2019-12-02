#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll r,b,k;

void solve()
{
    scanf("%lld%lld%lld",&r,&b,&k);
    if(r>b) swap(r,b);
    if(__gcd(r,b)+(k-1)*r>=b) printf("OBEY\n");
    else printf("REBEL\n");
}

int main()
{
    int _=1;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
