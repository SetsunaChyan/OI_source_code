#include <bits/stdc++.h>
using namespace std;

int n,k,seg[200005<<2],lazy[200005<<2];
struct segment
{
    int l,r,pos;
}p[200005];
vector<int> ans;

inline bool cmp(segment a,segment b)
{
    return a.r<b.r;
}

inline void pushdown(int rt)
{
    if(lazy[rt]==0) return;
    seg[rt<<1]+=lazy[rt];
    seg[rt<<1|1]+=lazy[rt];
    lazy[rt<<1]+=lazy[rt];
    lazy[rt<<1|1]+=lazy[rt];
    lazy[rt]=0;
}

int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int ret=0,m=l+r>>1;
    pushdown(rt);
    if(L<=m) ret=max(ret,query(rt<<1,l,m,L,R));
    if(m<R) ret=max(ret,query(rt<<1|1,m+1,r,L,R));
    return ret;
}

void modify(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    {
        seg[rt]++;
        lazy[rt]++;
        return;
    }
    int m=l+r>>1;
    pushdown(rt);
    if(L<=m) modify(rt<<1,l,m,L,R);
    if(m<R) modify(rt<<1|1,m+1,r,L,R);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].l,&p[i].r);
        p[i].pos=i+1;
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(query(1,1,200000,p[i].l,p[i].r)>=k)
        {
            ans.push_back(p[i].pos);
            continue;
        }
        modify(1,1,200000,p[i].l,p[i].r);
    }
    printf("%d\n",(int)ans.size());
    for(auto a:ans)
        printf("%d ",a);
    return 0;
}
