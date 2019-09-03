#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l[1005],r[1005],n,L,R;
ll ans;

inline int cal(int l,int r)
{
    if(l==r) return 0;
    int ret=(r-l)/2;
    if((r-l)&1) ret++;
    return ret;
}

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",l+i,r+i);
    L=l[0],R=r[0];ans=0;
    for(int i=1;i<n;i++)
    {
        if(l[i]>R)
        {
            int k=cal(R,l[i]);
            ans+=k;
            L=max(l[i],R+2*(k-1)+1);
            R=min(r[i],R+2*k);
            continue;
        }
        if(r[i]<L)
        {
            int k=cal(r[i],L);
            ans+=k;
            R=min(r[i],L-2*(k-1)-1);
            L=max(l[i],L-2*k);
            continue;
        }
        L=max(l[i],L);
        R=min(r[i],R);
    }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
