#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll mod=998244353;
ll ans,cnt,cur,jc[300005];
int n;
pii p[300005];

bool cmp(pii a,pii b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]=make_pair(x,y);
    }
    jc[1]=1;
    for(int i=2;i<=n;i++) jc[i]=jc[i-1]*i%mod;
    ans=jc[n];
    sort(p,p+n);
    int flag=1;cnt=1;cur=1;
    for(int i=1;i<n;i++)
    {
        if(p[i].second<p[i-1].second)
        {
            flag=0;
            break;
        }
        else if(p[i].second==p[i-1].second) cur++;
        else cnt=cnt*jc[cur]%mod,cur=1;
    }
    cnt=cnt*jc[cur]%mod;
    if(flag) ans=(ans-cnt+mod)%mod;
    cnt=1;cur=1;
    for(int i=1;i<n;i++)
        if(p[i].first==p[i-1].first) cur++;
        else cnt=cnt*jc[cur]%mod,cur=1;
    cnt=cnt*jc[cur]%mod;
    if(!flag) ans=(ans-cnt+mod)%mod;
    sort(p,p+n,cmp);
    cnt=1;cur=1;flag=1;
    for(int i=1;i<n;i++)
    {
        if(p[i].first>p[i-1].first) flag=0;
        if(p[i].second==p[i-1].second) cur++;
        else cnt=cnt*jc[cur]%mod,cur=1;
    }
    cnt=cnt*jc[cur]%mod;
    if(!flag) ans=(ans-cnt+mod)%mod;
    printf("%lld",ans);
    return 0;
}
