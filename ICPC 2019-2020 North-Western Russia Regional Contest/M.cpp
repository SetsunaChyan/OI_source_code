#include <bits/stdc++.h>
using namespace std;

int n,a[2005],ans;
unordered_map<int,int> mp;

void solve()
{
    ans=0;
    mp.clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++) mp[a[j]]++;
        for(int j=i+1;j<n;j++)
        {
            mp[a[j]]--;
            ans+=mp[a[j]+a[j]-a[i]];//,printf("! %d %d %d\n",a[i],a[j],a[j]+a[j]-a[i]);
        }
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
