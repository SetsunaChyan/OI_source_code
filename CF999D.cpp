#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct P
{
    ll v;
    int pos;
}p[200005];
ll ans;
int n,m;

bool cmp(P x,P y){return x.v%m>y.v%m;}
bool cmp2(P x,P y){return x.pos<y.pos;}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld",&p[i].v),p[i].pos=i;
    sort(p,p+n,cmp);
    ll f=-1,t;
    for(int i=0;i<n;i++)
    {
        if(i%(n/m)==0) f++,f%=m;
        t=f;
        if(t<p[i].v%m) t+=m;
        ans+=t-p[i].v%m;
        p[i].v+=t-p[i].v%m;
    }
    sort(p,p+n,cmp2);
    printf("%lld\n",ans);
    for(int i=0;i<n;i++)
        printf("%lld ",p[i].v);
    return 0;
}
