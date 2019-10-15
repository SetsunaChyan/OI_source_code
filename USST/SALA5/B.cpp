#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

int n,m,k;
vector<int> qaq;
ll sum;
pli p[200005];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    ll x;
    for(int i=0;i<n;i++) scanf("%lld",&x),p[i]=make_pair(x,i);
    sort(p,p+n,greater<pli>());
    for(int i=0;i<m*k;i++)
        sum+=p[i].first,qaq.push_back(p[i].second+1);
    sort(qaq.begin(),qaq.end());
    printf("%lld\n",sum);
    for(int i=m-1;i<qaq.size()-m;i+=m)
        printf("%d ",qaq[i]);
    return 0;
}
