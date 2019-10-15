#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l,r,k,a[100005],sum;
int n;
deque<int> q;

ll check(ll x)
{
    ll s=0;
    for(int i=1;i<=n;i++)
        s+=min(a[i],x);
    return s;
}

int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),sum+=a[i],r=max(a[i],r);
    if(sum==k) return 0;
    if(sum<k)
    {
        printf("-1");
        return 0;
    }
    while(l<r)
    {
        ll m=(l+r+1)>>1;
        if(check(m)<=k) l=m; else r=m-1;
    }
    //l--;
    k-=check(l);
    for(int i=1;i<=n;i++)
        if(a[i]>l) q.push_back(i);
    //printf("qaq %lld %lld\n",k,l);
    while(k)
    {
        int c=q.front();
        q.pop_front();
        if(a[c]>l+1) q.push_back(c);
        k--;
    }
    while(!q.empty())
        printf("%d ",q.front()),q.pop_front();
    return 0;
}
