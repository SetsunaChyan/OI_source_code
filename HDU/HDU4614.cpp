#include <bits/stdc++.h>
using namespace std;

const int MAXN=50005;
int n,m,sum[MAXN<<2],lazy[MAXN<<2];

inline void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

inline void pushdown(int rt,int lnum,int rnum)
{
    if(lazy[rt]==-1) return;
    lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    sum[rt<<1]=lnum*lazy[rt],sum[rt<<1|1]=rnum*lazy[rt];
    lazy[rt]=-1;
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        sum[rt]=0;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(r>m) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        sum[rt]=x*(r-l+1);
        lazy[rt]=x;
        return;
    }
    int m=l+r>>1;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(R>m) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt);
}

int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return sum[rt];
    int m=l+r>>1,ret=0;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) ret+=query(rt<<1,l,m,L,R);
    if(R>m) ret+=query(rt<<1|1,m+1,r,L,R);
    return ret;
}

int fd(int l,int r,int x,int pre)
{
    while(l<r)
    {
        int m=l+r>>1;
        if(m-query(1,1,n,1,m)-pre>=x)
            r=m;
        else 
            l=m+1;
    }
    if(l-query(1,1,n,1,l)-pre!=x) return n+1;
    return l;
}

void solve()
{
    memset(lazy,-1,sizeof(lazy));
    scanf("%d%d",&n,&m);
    n;
    build(1,1,n);
    while(m--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        x++;
        if(op==1)
        {
            int pre=0,l=x,r=n;
            if(x>1) pre=x-1-query(1,1,n,1,x-1);
            y=min(y,n-query(1,1,n,1,n)-pre);
            int A=fd(l,r,1,pre),B=fd(l,r,y,pre);
            if(A>n) printf("Can not put any one.\n");
            else 
            {
                modify(1,1,n,A,B,1);
                printf("%d %d\n",A-1,B-1);
            }
        }
        else
        {
            y++;
            printf("%d\n",query(1,1,n,x,y));
            modify(1,1,n,x,y,0);
        }
    }
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}