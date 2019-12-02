#include <bits/stdc++.h>
using namespace std;

int n,a[105],vis[105];

void solve()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int T=n-2;T>=0;T--)
        for(int i=n-2;i>=0;i--)
            if(a[i]>a[i+1]&&!vis[i]) swap(a[i],a[i+1]),vis[i]=1;
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    puts("");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
