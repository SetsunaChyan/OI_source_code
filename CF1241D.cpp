#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[300005],tmp[300005],cnt[300005],vis[300005],dp[300005],ans;
vector<int> v;

void solve()
{
    v.clear();ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),tmp[i]=a[i];
    sort(tmp+1,tmp+1+n);
    int tot=unique(tmp+1,tmp+1+n)-tmp-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(tmp+1,tmp+tot+1,a[i])-tmp;
    for(int i=1;i<=tot;i++) cnt[i]=0,vis[i]=0,dp[i]=0;
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(!vis[a[i]]) vis[a[i]]=1,q.push(a[i]);
        cnt[a[i]]--;
        while(!q.empty()&&cnt[q.top()]==0) v.push_back(q.top()),q.pop();
    }
    for(int i=0;i<v.size();i++)
        dp[v[i]]=dp[v[i]-1]+1,ans=max(ans,dp[v[i]]);
    printf("%d\n",(int)v.size()-ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
