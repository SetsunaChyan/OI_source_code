#include <cstdio>
#include <memory.h>

typedef long long ll;
ll n,m,cnt[1005],sum,ans=(1ll<<63)-1,tmp;

inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for(ll i=1;i<=1000;i++)
    {
        ll kk1,kk2;
        sum=0;
        tmp=0;
        kk1=kk2=0;
        for(ll j=i;j<=1000&&kk1<m;j++)
        {
            sum+=j*min(m-kk1,cnt[j]);
            kk1+=min(m-kk1,cnt[j]);
        }
        if(kk1!=m) continue;
        for(ll j=i;j<=1000&&kk2<m;j++)
        {
            tmp+=min(m-kk2,cnt[j])*(m*j*j-2ll*j*sum);
            kk2+=min(m-kk2,cnt[j]);
        }
        tmp+=sum*sum;
        ans=min(ans,tmp);
    }
    for(ll i=1000;i>0;i--)
    {
        ll kk1,kk2;
        sum=0;
        tmp=0;
        kk1=kk2=0;
        for(ll j=i;j>0&&kk1<m;j--)
        {
            sum+=j*min(m-kk1,cnt[j]);
            kk1+=min(m-kk1,cnt[j]);
        }
        if(kk1!=m) continue;
        for(ll j=i;j>0&&kk2<m;j--)
        {
            tmp+=min(m-kk2,cnt[j])*(m*j*j-2ll*j*sum);
            kk2+=min(m-kk2,cnt[j]);
        }
        tmp+=sum*sum;
        ans=min(ans,tmp);
    }
    printf("%lld",ans);
    return 0;
}