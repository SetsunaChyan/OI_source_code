#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
vector<int> ans;

int main()
{
    scanf("%d%d",&n,&m);
    ll now=0;
    while(n--)
    {
        ll x;
        scanf("%lld",&x);
        ll tmp=x/m;
        now+=x%m;
        tmp+=now/m,now%=m;
        ans.push_back(tmp);
    }
    for(auto p:ans) printf("%d ",p);
    return 0;
}
