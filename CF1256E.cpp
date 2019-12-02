#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct P
{
    ll val;
    int pos;
};
int n,ans[200005],from[200005],num;
ll gap[200005],dp[200005],pre;
P p[200005];

inline bool cmp(P a,P b){return a.val<b.val;}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&p[i].val);
        p[i].pos=i;
    }
    memset(dp,0xc0,sizeof(dp));
    dp[0]=0;
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<n;i++) gap[i]=p[i+1].val-p[i].val;
    for(int i=3;i<=n;i++)
    {
        if(dp[i-3]>pre) pre=dp[i-3],num=i-3;
        dp[i]=pre+gap[i];
        from[i]=num;
    }
    int cur=n,tot=1;
    while(cur)
    {
        for(int i=from[cur]+1;i<=cur;i++) ans[p[i].pos]=tot;
        tot++;
        cur=from[cur];
    }
    printf("%lld %d\n",p[n].val-p[1].val-dp[n],tot-1);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}
