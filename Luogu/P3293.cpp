#include <bits/stdc++.h>
using namespace std;

int tot,n,m,root[200005],l,r,b,x,ans,k;
struct node
{
    int lc,rc,cnt;
}seg[200005*100];

int build(int l,int r)
{
    int p=++tot;
    seg[p].cnt=0;
    if(l==r) return p;
    int m=l+r>>1;
    seg[p].lc=build(l,m);
    seg[p].rc=build(m+1,r);
    return p;
}

int modify(int rt,int l,int r,int x)
{
    int p=++tot;
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

int query(int p,int q,int l,int r,int L,int R)
{
    if(L>R) return 0;
    if(L<=l&&r<=R) return seg[q].cnt-seg[p].cnt;
    int m=l+r>>1,ret=0;
    if(L<=m) ret+=query(seg[p].lc,seg[q].lc,l,m,L,R);
    if(m<R) ret+=query(seg[p].rc,seg[q].rc,m+1,r,L,R);
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    root[0]=build(1,100000);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        root[i]=modify(root[i-1],1,100000,x);
    }
    while(m--)
    {
        scanf("%d%d%d%d",&b,&x,&l,&r);
        ans=0;
        for(int i=20;i>=0;i--)
        {
            if(b&(1<<i))
            {
                if(!query(root[l-1],root[r],1,100000,max(1,ans-x),min(100000,ans+(1<<i)-1-x)))
                    ans|=1<<i;
            }
            else if(query(root[l-1],root[r],1,100000,max(1,ans+(1<<i)-x),min(100000,ans+(1<<(i+1))-1-x)))
                ans|=1<<i;
        }
        printf("%d\n",ans^b);
    }
    return 0;
}
