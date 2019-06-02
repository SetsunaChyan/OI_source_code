#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100050;
ll seg[MAXN<<2],lazy[MAXN<<2];
int n,m;

int _count(ll x)
{
    int ret=0;
    while(x) x-=x&-x,ret++;
    return ret;
}

inline void pushdown(int rt)
{
    if(!lazy[rt]) return;
    seg[rt<<1]|=lazy[rt];
    seg[rt<<1|1]|=lazy[rt];
    lazy[rt<<1]|=lazy[rt];
    lazy[rt<<1|1]|=lazy[rt];
    lazy[rt]=0;
}

inline void pushup(int rt){seg[rt]=seg[rt<<1]&seg[rt<<1|1];}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=0;
        lazy[rt]=0;
        return;
    }
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,ll x)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]|=x;
        seg[rt]|=x;
        return;
    }
    int m=l+r>>1;
    pushdown(rt);
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(R>m) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt);
}

ll query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1;
    ll ret=(1ll<<60)-1;
    pushdown(rt);
    if(L<=m) ret&=query(rt<<1,l,m,L,R);
    if(R>m) ret&=query(rt<<1|1,m+1,r,L,R);
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    build(1,1,n);
    while(m--)
    {
        int op,l,r,k,x;
        ll p=0;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1)
        {
            scanf("%d",&k);
            for(int i=0;i<k;i++)
                scanf("%d",&x),p|=1ll<<(x-1);
            modify(1,1,n,l,r,p);
        }
        else 
        {
            p=query(1,1,n,l,r);
            printf("%d\n",_count(p));
        }
    }
    return 0;
}