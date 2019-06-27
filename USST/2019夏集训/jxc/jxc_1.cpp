#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,num[500005],m,limit[500005];
double ans;
ll bit[500005],x,p,q;
vector<ll> v[500005];

void add(ll bit[],int x,ll y){for(;x<=m;x+=x&-x) bit[x]+=y;}

ll sum(ll bit[],int x)
{
    ll ret=0;
    for(;x;x-=x&-x) ret+=bit[x];
    return ret;
}

void solve()
{
    memset(bit,0,sizeof(bit));
    m=0,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&limit[i]);
    for(int i=0;i<n;i++)
    {
        v[i].clear();
        scanf("%d",&num[i]);
        m=max(m,num[i]);
        for(int j=0;j<num[i];j++)
            scanf("%lld",&x),v[i].push_back(x);
        sort(v[i].rbegin(),v[i].rend());
    }
    for(int i=0;i<n;i++)
    {
        if(num[i]<limit[i]) continue;
        for(int j=0;j<limit[i];j++) add(bit,limit[i],v[i][j]);
        for(int j=limit[i];j<num[i];j++) add(bit,j+1,v[i][j]);
    }
    for(int i=1;i<=m;i++)
    {
        ll tmp=sum(bit,i);
        if((double)tmp/i>ans) ans=(double)tmp/i,p=tmp,q=i;
    }
    ll tmp=__gcd(p,q);
    printf("%lld/%lld\n",p/tmp,q/tmp);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
