#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld%lld",&a,&b);
        if(a-b!=1) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}
