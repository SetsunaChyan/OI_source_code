#include <bits/stdc++.h>
using namespace std;

const int MAXN=50005;
int root[MAXN],X[MAXN],Y[MAXN],c1,c2,tot,n,m,a[MAXN],last;
struct segnode
{
    int lc,rc,cnt,sum;
}seg[MAXN*30];

namespace SEG
{
    void modify(int &rt,int l,int r,int x,int y)
    {
        if(!rt)
        {
            rt=++tot;
            seg[rt].cnt=seg[rt].sum=0;
        }
        if(l==r)
        {
            seg[rt].cnt+=y;
            seg[rt].sum+=y*l;
            return;
        }
        int m=l+r>>1;
        if(x<=m) modify(seg[rt].lc,l,m,x,y);
        else modify(seg[rt].rc,m+1,r,x,y);
        seg[rt].cnt=seg[seg[rt].lc].cnt+seg[seg[rt].rc].cnt;
        seg[rt].sum=seg[seg[rt].lc].sum+seg[seg[rt].rc].sum;
    }

    int query_sum(int l,int r,int L,int R)
    {
        int m=l+r>>l,ret=0;
        if(L<=l&&r<=R)
        {
            for(int i=0;i<c1;i++) ret-=seg[X[i].rc].sum;
            for(int i=0;i<c2;i++) ret+=seg[Y[i].lc].sum;
            return ret;
        }
        if(L<=m) ret+=query_sum(l,m,L,R);
        if(m<R) ret+=query_sum(m+1,r,L,R);
        return ret;
    }

    int query_num(int l,int r,int L,int R)
    {
        int m=l+r>>l,ret=0;
        if(L<=l&&r<=R)
        {
            for(int i=0;i<c1;i++) ret-=seg[X[i].rc].num;
            for(int i=0;i<c2;i++) ret+=seg[Y[i].lc].num;
            return ret;
        }
        if(L<=m) ret+=query_num(l,m,L,R);
        if(m<R) ret+=query_num(m+1,r,L,R);
        return ret;
    }
}

void modify(int x,int y,int z)
{
    for(;x<=n;x+=x&-x) SEG::modify(root[x],1,1000,y,z);
}

int query(int l,int r,int x,int flag)
{
    c1=c2=0;
    for(l--;l;l-=l&-l) X[c1++]=root[l];
    for(;r;r-=r&-r) Y[c2++]=root[r];
    if(flag==0) return SEG::query_sum(1,1000,x,1000);
    return SEG::query_num(1,1000,x,1000);
}

inline bool check(int l,int r,int x,int val)
{
    return query(l,r,x,0)<val;
}


int main()
{
    scanf("%*d%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        modify(i,a[i],1);
    }
    while(m--)
    {
        int op,L,R,k;
        scanf("%d%*d%d%*d%d%d",&op,&L,&R,&k);
        if(op==1)
        {
            modify(L,a[L],-1);
            a[L]=k;
            modify(L,k,1);
        }
        else
        {
            int l=
        }
    }
    return 0;
}
