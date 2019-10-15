#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll ans;
pair<ll,int> p[100];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x;ll y;
        scanf("%d%lld",&x,&y);
        p[i]=make_pair(y,x);
    }
    sort(p,p+m,greater<pair<ll,int>>());
    for(int i=0;i<m;i++)
    {
        if(p[i].second<n)
        {
            n-=p[i].second;
            ans+=p[i].first*p[i].second;
        }
        else
        {
            ans+=n*p[i].first;
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}
