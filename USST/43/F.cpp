#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200005;
ll seg[MAXN<<2],lazy[MAXN<<2],h[MAXN],l[MAXN],r[MAXN],pre[MAXN<<1];
int n;
pair<ll,int> e[MAXN<<1];

inline void pushup(int rt)
{
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

inline void pushdown(int rt)
{
    if(lazy[rt]==-1) return;
    seg[rt<<1]=max(seg[rt<<1],lazy[rt]);
    seg[rt<<1|1]=max(seg[rt<<1|1],lazy[rt]);
    lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    lazy[rt]=-1;
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=0;
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
        seg[rt]=max(seg[rt],x);
        lazy[rt]=x;
        return;
    }
    pushdown(rt);
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(R>m) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt);
}

ll query(int rt,int l,int r,int x)
{
    if(l==r) return seg[rt];
    pushdown(rt);
    int m=l+r>>1;
    if(x<=m) return query(rt<<1,l,m,x);
    else return query(rt<<1|1,m+1,r,x);
}

int main()
{
    memset(lazy,-1,sizeof(lazy));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        ll x,y;
        scanf("%lld%lld%lld",&x,&y,&h[i]);
        e[i*2]=make_pair(x,i*2);
        e[i*2+1]=make_pair(y,i*2+1);
    }
    sort(e,e+2*n);
    int k=1;
    for(int i=0;i<2*n;i++)
    {
        if(i&&e[i].first!=e[i-1].first) k++;
        pre[k]=e[i].first;
        int g=e[i].second;
        if(g&1) r[g/2]=k; else l[g/2]=k;
    }
    build(1,1,k);
    for(int i=0;i<n;i++)
        modify(1,1,k,l[i],r[i]-1,h[i]);

    //printf("\n\n");
    //for(int i=1;i<=k;i++)
    //    printf("%lld ",query(1,1,k,i));
    //printf("\n\n");


    //for(int i=0;i<n;i++)
    //    printf("%lld %lld %lld \n",l[i],r[i],h[i]);
    //printf("\n\n");
    ll last=0;
    for(int i=1;i<=k;i++)
    {
        ll now=query(1,1,k,i);
        //printf("de %d %lld\n",i,now);
        if(now!=last)
            printf("%lld %lld\n%lld %lld\n",pre[i],last,pre[i],now);
        //else if(now<last)
        //    printf("%lld %lld\n%lld %lld\n",pre[i-1],now);
        last=now;
    }
    //printf("%lld %lld\n%lld %lld\n",pre[k]+1,last,pre[k]+1,0ll);
    return 0;
}