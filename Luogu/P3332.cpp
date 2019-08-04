#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100005;
ll a,b,c;
int N,n,m,X1[MAXN],Y1[MAXN],X2[MAXN],Y2[MAXN],c1,c2,op;

struct SEG
{
    int tot,root[MAXN];
    struct node
    {
        ll cnt;
        int lc,rc;
    }seg[MAXN*100];
    void modify(int &rt,int l,int r,int x,int y)
    {
        if(!rt) rt=++tot;
        if(l==r)
        {
            seg[rt].cnt+=y;
            return;
        }
        int m=l+r>>1;
        if(x<=m) modify(seg[rt].lc,l,m,x,y);
        else modify(seg[rt].rc,m+1,r,x,y);
        seg[rt].cnt=seg[seg[rt].lc].cnt+seg[seg[rt].rc].cnt;
    }
}seg1,seg2;

int query(int l,int r,int L,int R,ll k)
{
    if(l==r) return l;
    int m=l+r>>1;
    ll sum=0;
    for(int i=0;i<c1;i++)
        sum-=seg1.seg[seg1.seg[X1[i]].rc].cnt*(L+1)-seg2.seg[seg2.seg[X2[i]].rc].cnt;
    for(int i=0;i<c2;i++)
        sum+=seg1.seg[seg1.seg[Y1[i]].rc].cnt*(R+1)-seg2.seg[seg2.seg[Y2[i]].rc].cnt;
    if(sum<k)
    {
        for(int i=0;i<c1;i++) X1[i]=seg1.seg[X1[i]].lc,X2[i]=seg2.seg[X2[i]].lc;
        for(int i=0;i<c2;i++) Y1[i]=seg1.seg[Y1[i]].lc,Y2[i]=seg2.seg[Y2[i]].lc;
        return query(l,m,L,R,k-sum);
    }
    else
    {
        for(int i=0;i<c1;i++) X1[i]=seg1.seg[X1[i]].rc,X2[i]=seg2.seg[X2[i]].rc;
        for(int i=0;i<c2;i++) Y1[i]=seg1.seg[Y1[i]].rc,Y2[i]=seg2.seg[Y2[i]].rc;
        return query(m+1,r,L,R,k);
    }
}

void add(int l,int r,int x)
{
    x+=n+1;
    for(int i=l;i<=N;i+=i&-i)
    {
        seg1.modify(seg1.root[i],1,N,x,1);
        seg2.modify(seg2.root[i],1,N,x,l);
    }
    for(int i=r+1;i<=N;i+=i&-i)
    {
        seg1.modify(seg1.root[i],1,N,x,-1);
        seg2.modify(seg2.root[i],1,N,x,-r-1);
    }
}

int kth(int l,int r,ll k)
{
    c1=c2=0;
    for(int i=l-1;i;i-=i&-i)
    {
        X1[c1]=seg1.root[i];
        X2[c1]=seg2.root[i];
        c1++;
    }
    for(int i=r;i;i-=i&-i)
    {
        Y1[c2]=seg1.root[i];
        Y2[c2]=seg2.root[i];
        c2++;
    }
    return query(1,N,l-1,r,k)-n-1;
}

int main()
{
    scanf("%d%d",&n,&m);
    N=2*n+1;
    while(m--)
    {
        scanf("%d%lld%lld%lld",&op,&a,&b,&c);
        if(op==1) add(a,b,c);
        else printf("%d\n",kth(a,b,c));
    }
    return 0;
}
