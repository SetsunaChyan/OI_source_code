#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k,m;
char s[1005];

void solve()
{
    scanf("%lld%lld%lld",&n,&k,&m);
    scanf("%s",s);
    int ans=0,now=0,lk=k;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') now++;
        else if(k) k--; else now--;
        ans=max(ans,now);
    }
    if(now>0)
    {
        printf("%lld\n",now*(m-1)+ans);
        return;
    }
    if(m<=1)
    {
        printf("%lld\n",ans);
        return;
    }
    ans=0,now=0,k=lk;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') now++;
        else if(k) k--; else now--;
        ans=max(ans,now);
    }
    k=lk;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') now++;
        else if(k) k--; else now--;
        ans=max(ans,now);
    }
    printf("%lld\n",ans);
}

signed main()
{
    int _;
    scanf("%lld",&_);
    while(_--) solve();
    return 0;
}
