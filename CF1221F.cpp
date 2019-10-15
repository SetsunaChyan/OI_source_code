#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,org[1000005],tmp[1000005],lp,rp;
ll lazy[1000005],mx[1000005],ans=-1e18;
struct Query
{
    int l,r;
    ll val;
}p[1000005];

inline void pushdown(int rt,ll lnum,ll rnum)
{
    lazy[rt<<1]+=lazy[rt];
    lazy[rt<<1|1]+=lazy[rt];
    mx[rt<<1]+=lazy[rt];
    mx[rt<<1|1]+=lazy[rt];
    lazy[rt]=0;
}

void build(int rt,int l,int r)
{
    mx[rt]=0;
    if(l==r) return;
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}

void modify(int rt,int l,int r,int L,int R,ll y)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]+=y;
        mx[rt]+=y;
        return;
    }
    int m=l+r>>1;
    if(lazy[rt]) pushdown(rt,m-l+1,r-m);
    if(L<=m) modify(rt<<1,l,m,L,R,y);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,y);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}

ll query(int rt,int l,int r,int L,int R,int &pos)
{
    if(L<=l&&r<=R) return mx[rt];
    int m=l+r>>1,np;
    ll ret=-1e18,tmp;
    if(lazy[rt]) pushdown(rt,m-l+1,r-m);
    if(L<=m)
    {
        tmp=query(rt<<1,l,m,L,R,np);
        if(tmp>ret) ret=tmp,pos=np;
    }
    if(m<R)
    {
        tmp=query(rt<<1,m+1,r,L,R,np);
        if(tmp>ret) ret=tmp,pos=np;
    }
    return ret;
}

bool cmp(Query a,Query b)
{
    return a.r<b.r;
}

int main()
{
    scanf("%d",&n);
    for(int i=0,x,y;i<n;i++)
    {
        scanf("%d%d%lld",&x,&y,&p[i].val);
        p[i].l=min(x,y);
        p[i].r=max(x,y);
        tmp[i<<1]=x,tmp[i<<1|1]=y;
    }
    sort(tmp,tmp+2*n);
    int tot=unique(tmp,tmp+2*n)-tmp,k;
    for(int i=0;i<n;i++)
    {
        k=lower_bound(tmp,tmp+tot,p[i].l)-tmp+1;
        org[k]=p[i].l;
        p[i].l=k;
        k=lower_bound(tmp,tmp+tot,p[i].r)-tmp+1;
        org[k]=p[i].r;
        p[i].r=k;
    }
    sort(p,p+n,cmp);
    p[n].r=-1,k=0;
    //build(1,1,tot);
    //printf("QAQ");
    while(k<n)
    {
        while(k<n&&p[k].r==p[k+1].r)
        {
            modify(1,1,tot,1,p[k].l,p[k].val-p[k].r+p[k].l);
            k++;
        }
        modify(1,1,tot,1,p[k].l,p[k].val-p[k].r+p[k].l);
        int pos;
        ll q=query(1,1,tot,1,p[k].r,pos);
        if(ans<q)
        {
            ans=q;
            lp=org[pos];
            rp=org[p[k].r];
        }
        if(k==n-1) break;
        k++;
        modify(1,1,tot,1,p[k].r,org[p[k].r]-org[p[k-1].r]);
    }
    printf("%lld\n%d %d %d %d\n",ans,lp,lp,rp,rp);
    return 0;
}
