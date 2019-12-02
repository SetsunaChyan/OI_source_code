#include <bits/stdc++.h>
using namespace std;

int n,k,a[100005];

bool check(int x)
{
    int cost=0,last=-0x3f3f3f3f;
    for(int i=0;i<n;i++)
        if(a[i]>=last+x) last=a[i],cost++;
    return cost<=k;
}

void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int mid,l=1,r=1000000000;
    while(l<r)
    {
        mid=l+r>>1;
        if(check(mid)) r=mid; else l=mid+1;
    }
    printf("%d\n",l);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
