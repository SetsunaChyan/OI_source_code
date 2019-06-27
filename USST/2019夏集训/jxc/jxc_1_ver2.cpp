#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,num[500005],m,limit[500005];
double ans;
ll sum[500005],x,p,q;
vector<ll> v[500005];

void solve()
{
    memset(sum,0,sizeof(sum));
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
        for(int j=0;j<limit[i];j++) sum[limit[i]]+=v[i][j];
        for(int j=limit[i];j<num[i];j++) sum[j+1]+=v[i][j];
    }
    sum[0]=0;
    for(int i=1;i<=m;i++) sum[i]+=sum[i-1];
    for(int i=1;i<=m;i++)
        if((double)sum[i]/i>ans) ans=(double)sum[i]/i,p=sum[i],q=i;
    printf("%lld/%lld\n",p/__gcd(p,q),q/__gcd(p,q));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
