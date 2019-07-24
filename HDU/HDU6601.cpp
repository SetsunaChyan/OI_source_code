#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;

const int MAXN=100005;
int n,m,root[MAXN],tot;
ui a[MAXN],tmp[MAXN],org[MAXN];
struct tree
{
    int cnt,lc,rc;
}seg[30*MAXN];

int build(int l,int r)
{
    int p=tot++;
    seg[p].cnt=0;
    if(l==r) return p;
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
    int rcnt=seg[seg[q].rc].cnt-seg[seg[p].rc].cnt;
    if(rcnt>=k) return query(seg[p].rc,seg[q].rc,m+1,r,k);
    else return query(seg[p].lc,seg[q].lc,l,m,k-rcnt);
}

void solve()
{
    tot=0;
    for(int i=1;i<=n;i++) scanf("%u",a+i),tmp[i]=a[i];
    sort(tmp+1,tmp+1+n);
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
        int x,y;
        scanf("%d%d",&x,&y);
        if(y-x<2)
        {
            printf("-1\n");
            continue;
        }
        ui a=org[query(root[x-1],root[y],1,n,1)],b=org[query(root[x-1],root[y],1,n,2)],c;
        for(int i=3;i<=y-x+1;i++)
        {
            c=org[query(root[x-1],root[y],1,n,i)];
            if(c+b>a) break;
            a=b,b=c,c=0;
        }
        if(c+b>a) printf("%u\n",a+b+c);
        else printf("-1\n");
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m)) solve();
    return 0;
}
