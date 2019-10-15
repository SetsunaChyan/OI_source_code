#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a,b,x,y,p[200005],tmp[200005],k;

bool check(int mid)
{
    ll ret=0,ta=a,tb=b,aa=x,bb=y,cur=1;
    for(int i=1;i<=mid;i++) tmp[i]=-1;
    if(aa<bb) swap(aa,bb),swap(ta,tb);
    for(int i=1;i<=mid;i++)
        if(i%ta==0&&i%tb==0) tmp[i]=p[cur++];
    for(int i=1;i<=mid;i++)
        if(i%ta==0&&tmp[i]==-1) tmp[i]=p[cur++];
    for(int i=1;i<=mid;i++)
        if(i%tb==0&&tmp[i]==-1) tmp[i]=p[cur++];
    for(int i=1;i<=mid;i++)
        if(tmp[i]==-1) tmp[i]=p[cur++];
    for(int i=1;i<=mid;i++)
    {
        if(i%ta==0) ret+=tmp[i]*aa;
        if(i%tb==0) ret+=tmp[i]*bb;
    }
    return ret>=k;
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]),p[i]/=100;
    scanf("%lld%lld%lld%lld%lld",&x,&a,&y,&b,&k);
    sort(p+1,p+n+1,greater<ll>());
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid)) r=mid; else l=mid+1;
    }
    if(!check(l)) printf("-1\n");
    else printf("%d\n",l);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
