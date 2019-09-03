#include <bits/stdc++.h>
using namespace std;

int n,ans,qaq,a[150005];

void solve()
{
    ans=0;qaq=0x3f3f3f3f;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>qaq) ans++;
        qaq=min(qaq,a[i]);
    }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
