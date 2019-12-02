#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m,ans,a[200005],mx,mxx;
pii p[200005];
deque<pii> v;
vector<pii> vv;

int get(int x)
{
    return lower_bound(vv.begin(),vv.end(),make_pair(x,-1))-vv.begin();
}

void solve()
{
    v.clear();
    vv.clear();
    ans=0;mx=0;mxx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i),mxx=max(mxx,a[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d%d",&p[i].first,&p[i].second),mx=max(p[i].first,mx);
    if(mxx>mx)
    {
        printf("-1\n");
        return;
    }
    sort(p,p+m);
    for(int i=0;i<m;i++)
    {
        while(!v.empty()&&v.back().second<=p[i].second) v.pop_back();
        v.push_back(p[i]);
    }
    while(!v.empty()) vv.push_back(v.front()),v.pop_front();
    int cur=get(a[0]),cnt=0;
    for(int i=0;i<n;)
    {
        while(i<n&&vv[cur].first>=a[i]&&cnt<vv[cur].second) i++,cnt++;
        if(i==n) break;
        if(cnt==vv[cur].second) ans++,cnt=0;
        cur=get(a[i]);
        if(cnt>=vv[cur].second) ans++,cnt=0;
    }
    printf("%d\n",ans+1);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
