#include <bits/stdc++.h>
using namespace std;

/*
    ��ɢ��+����kС
*/

const int MAXN=200005;
int n,m,a[MAXN],tmp[MAXN],org[MAXN],root[MAXN],tot=0;
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

int query(int p,int q,int l,int r,int k)
{
    if(l==r) return l;
    int m=l+r>>1;
    int lcnt=seg[seg[q].lc].cnt-seg[seg[p].lc].cnt;
    if(lcnt>=k) return query(seg[p].lc,seg[q].lc,l,m,k);
    else return query(seg[p].rc,seg[q].rc,m+1,r,k-lcnt);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),tmp[i]=a[i];
    sort(tmp+1,tmp+n+1);
    root[0]=build(1,n);
    for(int i=1;i<=n;i++)
    {
        int k=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
        org[k]=a[i];
        a[i]=k;
        root[i]=modify(root[i-1],1,n,a[i]);
    }
    while(m--)
    {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        printf("%d\n",org[query(root[x-1],root[y],1,n,k)]);
    }
    return 0;
}
