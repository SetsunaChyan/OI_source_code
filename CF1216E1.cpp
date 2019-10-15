#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int q;
ll mul[18],tmp[18],ff[60000];
ll n,ans;

int gao(ll cnt)
{
    int ret=0;
    while(cnt) cnt/=10,ret++;
    return ret;
}

void cal()
{
    ll sum=0,tmp=0,now=1;
    while(1)
    {
        tmp+=gao(now);
        sum+=tmp;
        ff[now]=sum;
        if(sum>=2e9) break;
        now++;
    }
}

int f(int len,int now,ll pos,ll num)
{
    //printf("QAQ %d %d %lld %lld\n",len,now,pos,num);
    if(now==0)
    {
        int tot=0;
        while(num)
            tmp[tot++]=num%10,num/=10;
        return tmp[tot-pos];
    }
    ll sum=0;
    for(int i=0;i<=9;i++)
    {
        if(i==0&&len==now) continue;
        if(sum<pos&&pos<=sum+len*(mul[now-1]))
            return f(len,now-1,pos-sum,num+i*mul[now-1]);
        sum+=len*(mul[now-1]);
    }
    assert(0);
    return -1;
}

signed main()
{
    cal();
    mul[0]=1;
    for(int i=1;i<=18;i++)
        mul[i]=10*mul[i-1];
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&n);
        int k=lower_bound(ff+1,ff+22000,n)-ff;
        n=n-ff[k-1];
        //printf("QAQ %lld\n",n);
        ll sum=0;
        for(int i=1;i<=10;i++)
        {
            if(sum<n&&n<=sum+9ll*(mul[i-1]))
            {
                ans=f(i,i,n-sum,0);
                break;
            }
            sum+=9ll*(mul[i-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
