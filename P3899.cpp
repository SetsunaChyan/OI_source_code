#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=300005;
int n,q,siz[MAXN],num[MAXN],dep[MAXN],root[MAXN],dfn[MAXN],cnt,tot,last;
struct node
{
    ll cnt;
    int lc,rc;
}seg[MAXN*40];
vector<int> e[MAXN];

int build(int l,int r)
{
    int p=++tot;
    seg[p].cnt=0;
    if(l==r)
    {
        return p;
    }
    int m=l+r>>1;
    seg[p].lc=build(l,m);
    seg[p].rc=build(m+1,r);
    return p;
}

int modify(int rt,int l,int r,int x,ll y)
{
    int p=++tot;
    seg[p]=seg[rt];
    if(l==r)
    {
        seg[p].cnt+=y;
        return p;
    }
    int m=l+r>>1;
    if(x<=m) seg[p].lc=modify(seg[rt].lc,l,m,x,y);
    else seg[p].rc=modify(seg[rt].rc,m+1,r,x,y);
    seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
    return p;
}

ll query(int p,int q,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[q].cnt-seg[p].cnt;
    ll ret=0;
    int m=l+r>>1;
    if(L<=m) ret+=query(seg[p].lc,seg[q].lc,l,m,L,R);
    if(m<R) ret+=query(seg[p].rc,seg[q].rc,m+1,r,L,R);
    return ret;
}

void dfs(int now,int fa)
{
    dep[now]=dep[fa]+1;
    dfn[now]=++cnt;
    num[cnt]=now;
    siz[now]=1;
    for(auto &to:e[now])
    {
        if(to==fa) continue;
        dfs(to,now);
        siz[now]+=siz[to];
    }
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1,u,v;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    root[0]=build(1,n);
    dfs(1,0);
    for(int i=1;i<=n;i++)
        root[i]=modify(root[i-1],1,n,dep[num[i]],siz[num[i]]-1);
    while(q--)
    {
        ll ans=0;
        int p,k;
        scanf("%d%d",&p,&k);
        ans+=min(dep[p]-1,k)*(siz[p]-1ll);
        ans+=query(root[dfn[p]-1],root[dfn[p]+siz[p]-1],1,n,min(n,dep[p]+1),min(dep[p]+k,n));
        printf("%lld\n",ans);
    }
    return 0;
}
