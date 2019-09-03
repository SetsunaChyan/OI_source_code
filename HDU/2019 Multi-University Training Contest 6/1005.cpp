#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SEG
{
    ll sum,pre,suf,sub;
}seg[2005<<2];
struct Point
{
    int x,y;
    ll val;
}p[2005];
ll tmpx[2005],tmpy[2005],ans;
int n,id[2005],N,M;

bool cmp(Point a,Point b)
{
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}

inline void pushup(int rt)
{
    int lc=rt<<1,rc=rt<<1|1;
    seg[rt].sum=seg[lc].sum+seg[rc].sum;
    seg[rt].pre=max(seg[lc].pre,seg[lc].sum+seg[rc].pre);
    seg[rt].suf=max(seg[rc].suf,seg[rc].sum+seg[lc].suf);
    seg[rt].sub=max(seg[lc].sub,seg[rc].sub);
    seg[rt].sub=max(seg[rt].sub,seg[lc].suf+seg[rc].pre);
}

void build(int rt,int l,int r)
{
    seg[rt].sum=seg[rt].pre=seg[rt].suf=seg[rt].sub=0;
    if(l==r) return;
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}

void modify(int rt,int l,int r,int x,ll y)
{
    if(l==r)
    {
        seg[rt].sum+=y;
        seg[rt].pre=seg[rt].suf=seg[rt].sub=max(0ll,seg[rt].sum);
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    pushup(rt);
}

void solve()
{
    ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%lld",&p[i].x,&p[i].y,&p[i].val);
        tmpx[i]=p[i].x;
        tmpy[i]=p[i].y;
    }
    sort(tmpx,tmpx+n);
    sort(tmpy,tmpy+n);
    N=unique(tmpx,tmpx+n)-tmpx;
    M=unique(tmpy,tmpy+n)-tmpy;
    for(int i=0;i<n;i++)
    {
        p[i].x=lower_bound(tmpx,tmpx+N,p[i].x)-tmpx+1;
        p[i].y=lower_bound(tmpy,tmpy+M,p[i].y)-tmpy+1;
    }
    sort(p,p+n,cmp);
    for(int i=0;i<=n;i++) id[i]=0x3f3f3f3f;
    for(int i=0;i<n;i++)
        id[p[i].y]=min(i,id[p[i].y]);
    id[p[n-1].y+1]=n;
    for(int i=1;i<=M;i++)
    {
        build(1,1,N);
        for(int j=i;j<=M;j++)
        {
            for(int k=id[j];k<id[j+1];k++)
                modify(1,1,N,p[k].x,p[k].val);
            ans=max(ans,seg[1].sub);
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
