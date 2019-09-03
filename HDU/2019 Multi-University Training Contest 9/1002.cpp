#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll ans;
int n,k,m,tmpx[100005],tmpy[100005],bit[100005];
struct opt
{
    int x,y;
    char typ;
}op[100005];

void add(int x,int y)
{
    for(;x<=n;x+=x&-x) bit[x]+=y;
}

int sum(int x)
{
    int ret=0;
    for(;x;x-=x&-x) ret+=bit[x];
    return ret;
}

bool cmp1(opt a,opt b)
{
    if(a.y!=b.y) return a.y<b.y;
    if(a.typ=='L'||a.typ=='R')
        if(b.typ=='U'||b.typ=='D') return 1;
    return 0;
}

bool cmp2(opt a,opt b)
{
    if(a.y!=b.y) return a.y>b.y;
    if(a.typ=='L'||a.typ=='R')
        if(b.typ=='U'||b.typ=='D') return 1;
    return 0;
}

void solve()
{
    ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d %c",&op[i].x,&op[i].y,&op[i].typ);
        tmpx[i]=op[i].x;
        tmpy[i]=op[i].y;
    }
    sort(tmpx,tmpx+k);
    sort(tmpy,tmpy+k);
    n=unique(tmpx,tmpx+k)-tmpx;
    m=unique(tmpy,tmpy+k)-tmpy;
    for(int i=0;i<k;i++)
    {
        op[i].x=lower_bound(tmpx,tmpx+n,op[i].x)-tmpx+1;
        op[i].y=lower_bound(tmpy,tmpy+m,op[i].y)-tmpy+1;
    }
    sort(op,op+k,cmp1);
    for(int i=0;i<=n;i++) bit[i]=0;
    for(int i=0;i<k;i++)
    {
        if(op[i].typ=='D')
            ans+=sum(op[i].x);
        else if(op[i].typ=='L')
            add(1,1),add(op[i].x+1,-1);
        else if(op[i].typ=='R')
            add(op[i].x,1);
    }
    sort(op,op+k,cmp2);
    for(int i=0;i<=n;i++) bit[i]=0;
    for(int i=0;i<k;i++)
    {
        if(op[i].typ=='U')
            ans+=sum(op[i].x);
        else if(op[i].typ=='L')
            add(1,1),add(op[i].x+1,-1);
        else if(op[i].typ=='R')
            add(op[i].x,1);
    }
    printf("%lld\n",ans+1);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
