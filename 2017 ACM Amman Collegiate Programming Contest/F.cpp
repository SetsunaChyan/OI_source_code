#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,a[100005],k,last[100005];
map<int,int> mp,gao;
set<pii> s;

void solve()
{
    gao.clear();
    s.clear();
    mp.clear();
    scanf("%d%d",&n,&k);
    int ans=0,cur=1;
    for(int i=1;i<=n;i++) scanf("%d",a+i),mp[a[i]]=0x3f3f3f3f;
    for(int i=n;i>=1;i--)
        last[i]=mp[a[i]],mp[a[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(s.count(make_pair(gao[a[i]],a[i])))
            s.erase(s.find(make_pair(gao[a[i]],a[i])));
        else
            ans++;
        s.emplace(last[i],a[i]),gao[a[i]]=last[i];
        if(s.size()==k)
        {
            cur=i;
            break;
        }
    }
    for(int i=cur+1;i<=n;i++)
    {
        if(s.count(make_pair(gao[a[i]],a[i])))
            s.erase(s.find(make_pair(gao[a[i]],a[i])));
        else
        {
            auto ed=s.end();ed--;
            s.erase(ed);ans++;
        }
        s.emplace(last[i],a[i]),gao[a[i]]=last[i];
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
