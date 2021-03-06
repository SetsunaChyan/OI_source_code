#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    modify 将区间大于x的数变成x
    query 询问区间和
    单次复杂度 O(log^2(n))
*/

const ll INF=0xc0c0c0c0c0c0c0c0ll;
const int MAXN=200005;
ll seg[MAXN<<2],m1[MAXN<<2],m2[MAXN<<2],cnt[MAXN<<2],tag[MAXN<<2],a[MAXN];
int n,q;

void pushdown(int rt)
{
    if(!tag[rt]) return;
    ll y=m1[rt];
    if(y<m1[rt<<1])
    {
        tag[rt<<1]=1;
        seg[rt<<1]-=(m1[rt<<1]-y)*cnt[rt<<1];
        m1[rt<<1]=y;
    }
    if(y<m1[rt<<1|1])
    {
        tag[rt<<1|1]=1;
        seg[rt<<1|1]-=(m1[rt<<1|1]-y)*cnt[rt<<1|1];
        m1[rt<<1|1]=y;
    }
    tag[rt]=0;
}

void pushup(int rt)
{
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
    if(m1[rt<<1]==m1[rt<<1|1])
    {
        m1[rt]=m1[rt<<1];
        cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
        m2[rt]=max(m2[rt<<1],m2[rt<<1|1]);
    }
    else if(m1[rt<<1]>m1[rt<<1|1])
    {
        m1[rt]=m1[rt<<1];
        cnt[rt]=cnt[rt<<1];
        m2[rt]=max(m2[rt<<1],m1[rt<<1|1]);
    }
    else
    {
        m1[rt]=m1[rt<<1|1];
        cnt[rt]=cnt[rt<<1|1];
        m2[rt]=max(m2[rt<<1|1],m1[rt<<1]);
    }
}

void build(int rt,int l,int r)
{
    tag[rt]=0;
    if(l==r)
    {
        seg[rt]=m1[rt]=a[l];
        cnt[rt]=1;
        m2[rt]=INF;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,ll y)
{
    if(y>=m1[rt]) return;
    if(L<=l&&r<=R&&y>m2[rt])
    {
        tag[rt]=1;
        seg[rt]-=(m1[rt]-y)*cnt[rt];
        m1[rt]=y;
        return;
    }
    pushdown(rt);
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R,y);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,y);
    pushup(rt);
}

ll query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1;
    pushdown(rt);
    ll ret=0;
    if(L<=m) ret+=query(rt<<1,l,m,L,R);
    if(m<R) ret+=query(rt<<1|1,m+1,r,L,R);
    pushup(rt);
    return ret;
}

int main()
{

    return 0;
}
