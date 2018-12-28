#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n,a[100005];

inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    printf("%lld",min(a[n]-a[2],a[n-1]-a[1]));
    return 0;
}