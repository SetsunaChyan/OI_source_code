#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,d,r,vis1[100005],vis2[100005];

//kd%n==gr%n
// 1 2 3 4  5 1 2 3  4 5 1 2
// 1          2       3

void solve()
{
    scanf("%d%d%d",&n,&d,&r);
    int k=__gcd(n,__gcd(d,r));
    n/=k,d/=k,r/=k;
    int ans=0x3f3f3f3f,cur=d%n,cnt=0;
    for(int i=0;i<n;i++) vis1[i]=vis2[i]=0x3f3f3f3f;
    while(vis1[cur]==0x3f3f3f3f) vis1[cur]=++cnt,cur+=d,cur%=n;
    cur=r%n,cnt=0;
    while(vis2[cur]==0x3f3f3f3f)
    {
        vis2[cur]=++cnt;
        ans=min(ans,max(vis1[cur],cnt));
        //printf("! %d %d\n",vis1[cur],cnt);
        cur+=r,cur%=n;
    }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

