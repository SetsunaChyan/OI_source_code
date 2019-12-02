#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[200005];
int last[200005];

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),last[i]=0;
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        if(last[a[i]]!=0)
            ans=min(ans,i-last[a[i]]+1);
        last[a[i]]=i;
    }
    printf("%d\n",ans==0x3f3f3f3f?-1:ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
