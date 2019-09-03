#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int n,k,a[MAXN],pos[MAXN],root[MAXN],tot,ans[MAXN];
struct tree
{
    int cnt,lc,rc;
}seg[30*MAXN];

int build(int l,int r)
{
    int p=tot++;
    if(l==r)
    {
        seg[p].cnt=0;
        return p;
    }
    int m=l+r>>1;
    seg[p].lc=build(l,m);
    seg[p].rc=build(m+1,r);
    seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
    return p;
}

int modify(int rt,int l,int r,int x)
{
    int p=tot++;
    seg[p]=seg[rt];
    if(l==r)
    {
        seg[p].cnt++;
        return p;
    }
    int m=l+r>>1;
    if(x<=m) seg[p].lc=modify(seg[rt].lc,l,m,x);
    else seg[p].rc=modify(seg[rt].rc,m+1,r,x);
    seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
    return p;
}

int getpre(int l,int r,int o1,int o2,int pos)
{
    if (!(seg[o2].cnt-seg[o1].cnt)) return 0;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(pos<=mid) return getpre(l,mid,seg[o1].lc,seg[o2].lc,pos);
    int t=getpre(mid+1,r,seg[o1].rc,seg[o2].rc,pos);
    if(t) return t;
    return getpre(l,mid,seg[o1].lc,seg[o2].lc,pos);
}

void solve()
{
    tot=0;
    scanf("%d%d",&n,&k);
    root[0]=build(1,n);
    for(int i=1;i<=n;i++)
    {
        ans[i]=0;
        scanf("%d",a+i),pos[a[i]]=i;
        root[i]=modify(root[i-1],1,n,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int l=max(1,pos[i]-k)-1;
        int r=min(n,pos[i]+k);
        int k=getpre(1,n,root[l],root[r],i-1);
        ans[i]=ans[k]+1;
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",ans[i]," \n"[i==n]);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
