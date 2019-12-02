#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    轻重链剖分 单次复杂度 O(log^2(n))
    a[i] 表示dfs标号为i的点的值,而非点i的值
    1 x y z 表示将树从x到y结点最短路径上所有节点的值都加上z
    2 x y 表示求树从x到y结点最短路径上所有节点的值之和
    3 x z 表示将以x为根节点的子树内所有节点值都加上z
    4 x 表示求以x为根节点的子树内所有节点值之和
*/

const int MAXN=100005;
ll mod,lazy[MAXN<<2],seg[MAXN<<2],a[MAXN],tmp[MAXN];
int n,q,r,cnt,tot,dep[MAXN],top[MAXN],id[MAXN],son[MAXN],num[MAXN],fa[MAXN];
vector<int> e[MAXN];

void dfs1(int now,int f)
{
    dep[now]=dep[f]+1;
    fa[now]=f;
    num[now]=1;
    son[now]=0;
    for(auto to:e[now])
    {
        if(to==f) continue;
        dfs1(to,now);
        num[now]+=num[to];
        if(num[to]>num[son[now]]) son[now]=to;
    }
}

void dfs2(int now,int f)
{
    id[now]=++cnt;
    top[now]=f;
    if(son[now]) dfs2(son[now],f);
    for(auto to:e[now])
        if(to!=fa[now]&&to!=son[now])
            dfs2(to,to);
}

inline void pushdown(int rt,ll lnum,ll rnum)
{
    if(!lazy[rt]) return;
    seg[rt<<1]=(seg[rt<<1]+lazy[rt]*lnum%mod)%mod;
    seg[rt<<1|1]=(seg[rt<<1|1]+lazy[rt]*rnum%mod)%mod;
    lazy[rt<<1]=(lazy[rt<<1]+lazy[rt])%mod;
    lazy[rt<<1|1]=(lazy[rt<<1|1]+lazy[rt])%mod;
    lazy[rt]=0;
}

inline void pushup(int rt)
{
    seg[rt]=(seg[rt<<1]+seg[rt<<1|1])%mod;
}

void build(int rt,int l,int r)
{
    lazy[rt]=0;
    if(l==r)
    {
        seg[rt]=a[l]%mod;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,ll x)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]=(lazy[rt]+x)%mod;
        seg[rt]=(seg[rt]+x*(r-l+1)%mod)%mod;
        return;
    }
    int m=l+r>>1;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt);
}

ll query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1;
    ll ret=0;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) ret=(ret+query(rt<<1,l,m,L,R))%mod;
    if(m<R) ret=(ret+query(rt<<1|1,m+1,r,L,R))%mod;
    pushup(rt);
    return ret;
}

int main()
{
    scanf("%d%d%d%lld",&n,&q,&r,&mod);
    for(int i=1;i<=n;i++) scanf("%lld",&tmp[i]);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y),e[y].push_back(x);
    }
    num[0]=0,dep[r]=0;
    dfs1(r,r);
    dfs2(r,r);
    for(int i=1;i<=n;i++) a[id[i]]=tmp[i];
    build(1,1,n);

    while(q--)
    {
        int op,x,y;ll z;
        scanf("%d%d",&op,&x);
        if(op==4)
        {
            printf("%lld\n",query(1,1,n,id[x],id[x]+num[x]-1));
            continue;
        }
        if(op==1)
        {
            scanf("%d%lld",&y,&z);z%=mod;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                modify(1,1,n,id[top[x]],id[x],z);
                x=fa[top[x]];
            }
            if(dep[x]>dep[y]) swap(x,y);
            modify(1,1,n,id[x],id[y],z);
        }
        else if(op==2)
        {
            scanf("%d",&y);
            ll ans=0;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                ans=(ans+query(1,1,n,id[top[x]],id[x]))%mod;
                x=fa[top[x]];
            }
            if(dep[x]>dep[y]) swap(x,y);
            ans=(ans+query(1,1,n,id[x],id[y]))%mod;
            printf("%lld\n",ans);
        }
        else
        {
            scanf("%lld",&z);z%=mod;
            modify(1,1,n,id[x],id[x]+num[x]-1,z);
        }
    }
    return 0;
}
