#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=0;
int n,a[100005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    ll tot=1;
    ans++;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) tot++;
        else tot=1;
        ans+=tot;
    }
    printf("%lld",ans);
    return 0;
}
