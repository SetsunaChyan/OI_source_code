#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,n,m,sum,cnt;
int vis[10];

void solve()
{
    memset(vis,0,sizeof(vis));
    scanf("%lld%lld",&n,&m);
    ll now=m;sum=cnt=0;
    if(n<m)
    {
        printf("0\n");
        return;
    }
    while(!vis[now%10]&&now<=n)
    {
        vis[now%10]++;
        sum+=now%10;
        cnt++;
        now+=m;
    }
    ans=n/(cnt*m)*sum;
    now=n/(cnt*m)*(cnt*m)+m;
    while(now<=n)
    {
        ans+=now%10;
        now+=m;
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
