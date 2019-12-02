#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int sum[MAXN<<2],mx[MAXN<<2],mm[MAXN<<2],a[MAXN],n,m;

inline void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    mm[rt]=min(mm[rt<<1],mm[rt<<1|1]);
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        sum[rt]=mx[rt]=mm[rt]=a[l];
        return;
    }
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int x,int y)
{
    if(l==r)
    {
        sum[rt]=mx[rt]=mm[rt]=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    pushup(rt);
}

int query_sum(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return sum[rt];
    int m=l+r>>1,ret=0;
    if(L<=m) ret+=query_sum(rt<<1,l,m,L,R);
    if(m<R) ret+=query_sum(rt<<1|1,m+1,r,L,R);
    return ret;
}

int query_mx(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return mx[rt];
    int m=l+r>>1,ret=0;
    if(L<=m) ret=max(ret,query_mx(rt<<1,l,m,L,R));
    if(m<R) ret=max(ret,query_mx(rt<<1|1,m+1,r,L,R));
    return ret;
}

int query_mm(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return mm[rt];
    int m=l+r>>1,ret=0x3f3f3f3f;
    if(L<=m) ret=min(ret,query_mm(rt<<1,l,m,L,R));
    if(m<R) ret=min(ret,query_mm(rt<<1|1,m+1,r,L,R));
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    build(1,1,n);
    while(m--)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1) printf("%d\n",query_sum(1,1,n,l,r)-query_mx(1,1,n,l,r)-query_mm(1,1,n,l,r));
        else modify(1,1,n,l,r);
    }
    return 0;
}
