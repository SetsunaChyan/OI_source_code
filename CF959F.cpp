#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

#define x first
#define pos second
const ll mod=1e9+7;
int n,q,a[100005],ans[100005],d[25],tot;
vector<pii> query[100005];

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

void add(int x)
{
    for(int i=20;i>=0;i--)
        if(x&(1<<i))
            if(d[i]==0)
            {
                d[i]=x;
                tot++;
                return;
            }
            else x^=d[i];
}

bool have(int x)
{
    for(int i=20;i>=0;i--)
        if(x&(1<<i))
            if(d[i]==0) return false;
            else x^=d[i];
    return true;
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=0,l,val;i<q;i++)
        scanf("%d%d",&l,&val),query[l].emplace_back(val,i);
    for(int i=1;i<=n;i++)
    {
        add(a[i]);
        for(auto p:query[i])
            if(!have(p.x)) ans[p.pos]=0;
            else ans[p.pos]=fp(2,i-tot);
    }
    for(int i=0;i<q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
