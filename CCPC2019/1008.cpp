#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

priority_queue<pli> q;
ll ans;

void solve()
{
    ans=0;
    while(!q.empty()) q.pop();
    scanf("%d%d",&n,&k);
    while(n--)
    {
        ll x;
        scanf("%lld",&x);
        q.emplace(k-x%k,x);
    }
    while(!q.empty())
    {
        ans+=x-q.top()+k*q.top();
        x
    }
    printf("%lld",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
