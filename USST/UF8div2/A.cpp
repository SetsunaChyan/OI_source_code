#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,qaq,t;
int vis[100005];
vector<ll> ans;

int main()
{
    scanf("%lld%lld%lld",&n,&k,&qaq);
    qaq%=k;
    for(int i=1;i<n;i++)
        scanf("%lld",&t),t%=k,qaq=__gcd(qaq,t);
    t=qaq;
    while(vis[qaq]==0)
    {
        vis[qaq]=1;
        ans.push_back(qaq);
        qaq+=t,qaq%=k;
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%lld ",p);
    return 0;
}
