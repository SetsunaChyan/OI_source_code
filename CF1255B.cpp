#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m,s;
pii a[10005];
vector<pii> ans;

void solve()
{
    s=0;ans.clear();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].first),a[i].second=i,s+=2*a[i].first;
    if(n==2)
    {
        printf("-1\n");
        return;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
        m--,ans.emplace_back(i,i+1);
    m--,ans.emplace_back(n,1);
    if(m<0)
    {
        printf("-1\n");
        return;
    }
    while(m--) ans.emplace_back(a[1].second,a[2].second),s+=a[1].first+a[2].first;
    printf("%d\n",s);
    for(auto p:ans) printf("%d %d\n",p.first,p.second);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

