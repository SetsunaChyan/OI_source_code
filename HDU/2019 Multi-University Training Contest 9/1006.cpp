#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[1000],qaq,dp[5000];

void solve()
{
    qaq=0;
    int ans=0,mx=0,flag=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i),qaq+=a[i]%10;
    if(qaq)
    {
        printf("-1\n");
        return;
    }
    int state=0;
    for(int i=0;i<n;i++)
    {
        ll tmp=(a[i]%100)/10;
        if(a[i]==10) flag=1;
        if(tmp!=0) state|=1<<(tmp-1);
        mx=max(mx,a[i]);
    }
    ans=dp[state]+mx/100;
    if(mx/100*100+10!=mx)
    {
        printf("%d\n",ans);
        return;
    }
    for(int i=0;i<n;i++)
        if(a[i]==mx/100*100+10) state|=1<<9;
    if(state&(1<<9))
        if(!flag)
        {
            state-=1;
            ans=min(ans,dp[state]+mx/100-1);
        }
    printf("%d\n",ans);
}

bool check(int wp,int okane)
{
    vector<int> a;
    bool vis[12];
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    if(okane&(1<<0)) a.push_back(1);
    if(okane&(1<<1)) a.push_back(1);
    if(okane&(1<<2)) a.push_back(1);
    if(okane&(1<<3)) a.push_back(1);
    if(okane&(1<<4)) a.push_back(2);
    if(okane&(1<<5)) a.push_back(2);
    if(okane&(1<<6)) a.push_back(2);
    if(okane&(1<<7)) a.push_back(2);
    if(okane&(1<<8)) a.push_back(5);
    for(int i=0;i<a.size();i++)
        for(int j=11;j>=a[i];j--)
            vis[j]|=vis[j-a[i]];
    for(int i=1;i<10;i++)
        if(wp&(1<<(i-1)))
            if(!vis[i]) return false;
    if(wp&(1<<9))
        if(!vis[11]) return false;
    return true;
}

int main()
{
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<9);j++)
            if(check(i,j))
                dp[i]=min(dp[i],__builtin_popcount(j));
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
