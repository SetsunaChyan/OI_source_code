#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int ans,n,c,k,tag[MAXN<<2],seg[MAXN<<2],a[MAXN],cnt[MAXN];
vector<int> pos[MAXN];

void pushup(int rt)
{
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

void pushdown(int rt)
{
    if(!tag[rt]) return;
    seg[rt<<1]+=tag[rt],tag[rt<<1]+=tag[rt];
    seg[rt<<1|1]+=tag[rt],tag[rt<<1|1]+=tag[rt];
    tag[rt]=0;
}

void build(int rt,int l,int r)
{
    tag[rt]=0;
    if(l==r)
    {
        seg[rt]=0;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L>R) return;
    if(L<=l&&r<=R)
    {
        tag[rt]+=x;
        seg[rt]+=x;
        return;
    }
    pushdown(rt);
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt);
}

int query(int rt,int l,int r,int L,int R)
{
    if(l==r) return l;
    pushdown(rt);
    int m=l+r>>1;
    if(L<=m&&seg[rt<<1]==c) return query(rt<<1,l,m,L,R);
    if(m<R&&seg[rt<<1|1]==c) return query(rt<<1|1,m+1,r,L,R);
    return -1;
}

void solve()
{
    ans=0;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=c;i++)
    {
        cnt[i]=0;
        pos[i].clear();
        pos[i].shrink_to_fit();
        pos[i].push_back(0);
    }
    for(int i=1;i<=n;i++)
        pos[a[i]].push_back(i);
    for(int i=1;i<=c;i++)
        pos[i].push_back(n+1);
    build(1,1,n);
    for(int i=1;i<=c;i++)
        modify(1,1,n,pos[i][0]+1,pos[i][1]-1,1);
    for(int i=1;i<=n;i++)
    {
        int p=++cnt[a[i]];
        modify(1,1,n,pos[a[i]][p-1]+1,pos[a[i]][p]-1,-1);
        modify(1,1,n,pos[a[i]][p]+1,pos[a[i]][p+1]-1,1);
        if(p>=k) modify(1,1,n,pos[a[i]][p-k]+1,pos[a[i]][p-k+1],1);
        int l=query(1,1,n,1,i);
        if(l!=-1) ans=max(ans,i-query(1,1,n,1,i)+1);
    }
    printf("%d\n",ans);
}

int main()
{
    while(~scanf("%d%d%d",&n,&c,&k)) solve();
    return 0;
}
