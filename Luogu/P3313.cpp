#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int n,q,a[MAXN],b[MAXN],tot,x,y,root[MAXN];
int dep[MAXN],top[MAXN],son[MAXN],siz[MAXN],id[MAXN],fa[MAXN],cnt;
char op[5];
struct node
{
    int lc,rc,sum,mx;
}seg[MAXN*30];
vector<int> e[MAXN];

void modify(int &rt,int l,int r,int x,int y)
{
    if(rt==0) rt=++tot;
    if(l==r)
    {
        seg[rt].sum+=y;
        seg[rt].mx+=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(seg[rt].lc,l,m,x,y);
    else modify(seg[rt].rc,m+1,r,x,y);
    seg[rt].mx=max(seg[seg[rt].lc].mx,seg[seg[rt].rc].mx);
    seg[rt].sum=seg[seg[rt].lc].sum+seg[seg[rt].rc].sum;
}

int query(int rt,int l,int r,int L,int R,int opt)
{
    if(rt==0||r<L||l>R) return 0;
    if(L<=l&&r<=R)
        if(opt) return seg[rt].mx; else return seg[rt].sum;
    int m=l+r>>1;
    if(opt)
        return max(query(seg[rt].lc,l,m,L,R,opt),query(seg[rt].rc,m+1,r,L,R,opt));
    else
        return query(seg[rt].lc,l,m,L,R,opt)+query(seg[rt].rc,m+1,r,L,R,opt);
}

void dfs1(int now,int u)
{
    dep[now]=dep[u]+1;
    fa[now]=u;
    siz[now]=1;
    for(auto to:e[now])
        if(to!=u)
        {
            dfs1(to,now);
            siz[now]+=siz[to];
            if(siz[to]>siz[son[now]]) son[now]=to;
        }
}

void dfs2(int now,int u)
{
    top[now]=u;
    id[now]=++cnt;
    if(son[now]) dfs2(son[now],u);
    for(auto to:e[now])
        if(to!=son[now]&&to!=fa[now])
            dfs2(to,to);
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d%d",a+i,b+i);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++)
        modify(root[b[i]],1,n,id[i],a[i]);
    while(q--)
    {
        scanf("%s%d%d",op,&x,&y);
        if(op[1]=='C')
        {
            modify(root[b[x]],1,n,id[x],-a[x]);
            modify(root[b[x]=y],1,n,id[x],a[x]);
        }
        else if(op[1]=='W')
        {
            modify(root[b[x]],1,n,id[x],-a[x]);
            modify(root[b[x]],1,n,id[x],a[x]=y);
        }
        else if(op[1]=='S')
        {
            int ans=0,c=x;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                ans+=query(root[b[c]],1,n,id[top[x]],id[x],0);
                x=fa[top[x]];
            }
            if(dep[x]<dep[y]) swap(x,y);
            ans+=query(root[b[c]],1,n,id[y],id[x],0);
            printf("%d\n",ans);
        }
        else if(op[1]=='M')
        {
            int ans=0,c=x;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                ans=max(ans,query(root[b[c]],1,n,id[top[x]],id[x],1));
                x=fa[top[x]];
            }
            if(dep[x]<dep[y]) swap(x,y);
            ans=max(ans,query(root[b[c]],1,n,id[y],id[x],1));
            printf("%d\n",ans);
        }
    }
    return 0;
}
