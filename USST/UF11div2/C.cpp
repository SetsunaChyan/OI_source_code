#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll l,r,a[1005],mm,mx,w;

int main()
{
    scanf("%d%lld",&n,&w);
    ll now=0;
    for(int i=0;i<n;i++)
        scanf("%lld",a+i),now+=a[i],mx=max(now,mx),mm=min(now,mm);
    printf("%lld",max(0ll,w-(mx-mm)+1));
    return 0;
}
