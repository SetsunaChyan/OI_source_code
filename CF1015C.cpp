#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int n;
ll m,sum;
pii p[100005];

inline bool cmp(pii a,pii b){return a.first-a.second>b.first-b.second;}

int main()
{
    scanf("%d%lld",&n,&m);
    for(int i=0,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        p[i]={x,y};
        sum+=x;
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(sum<=m) return printf("%d",i),0;
        sum-=p[i].first-p[i].second;
    }
    if(sum<=m) return printf("%d",n),0;
    printf("-1");
    return 0;
}
